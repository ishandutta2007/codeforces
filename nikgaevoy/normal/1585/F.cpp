#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);

template<class T>
using fast_stack = stack<T, vector<T>>;

template<size_t sz>
class chunk_alloc
{
public:
	static constexpr auto chunk_size = sz;

private:
	using chunk_t = array<byte, chunk_size>;

	deque<chunk_t> mem;
	fast_stack<void *> emp;

public:
	void *allocate()
	{
		if (emp.empty())
			emp.push(reinterpret_cast<void *>(&mem.emplace_back()));

		auto ans = emp.top();
		emp.pop();

		return ans;
	}


	void deallocate(void *p) noexcept
	{
		emp.push(p);
	}
};


chunk_alloc<72> pool;


template<class T>
class dummy_alloc
{
public:
	using value_type = T;

	dummy_alloc() noexcept
	{}

	template<class U>
	dummy_alloc(const dummy_alloc<U> &) noexcept
	{}

	T *allocate(std::size_t n)
	{
		if constexpr (sizeof(value_type) == decltype(pool)::chunk_size)
			return static_cast<T *>(pool.allocate());
		else
			return static_cast<T *>(::operator new(n * sizeof(value_type)));
	}

	void deallocate(T *p, std::size_t n)
	{
		if constexpr (sizeof(value_type) == decltype(pool)::chunk_size)
			return pool.deallocate(p);
		else
			::delete (p);
	}
};

template<class T, class U>
constexpr bool operator==(const dummy_alloc<T> &, const dummy_alloc<U> &) noexcept
{ return true; }

template<class T, class U>
constexpr bool operator!=(const dummy_alloc<T> &, const dummy_alloc<U> &) noexcept
{ return false; }


template<unsigned mod>
class modulo
{
	static_assert(mod <= numeric_limits<unsigned>::max() / 2);

	unsigned x;

public:
	explicit modulo(unsigned x = 0) : x(x)
	{}

	explicit modulo(ull x) : x(x % mod)
	{}

	bool operator==(const modulo &rhs) const = default;

	bool operator!=(const modulo &rhs) const = default;

	explicit operator unsigned() const
	{
		return x;
	}

	explicit operator int() const
	{
		return x;
	}

	modulo operator+(const modulo &rhs) const
	{
		auto ans = x + rhs.x;

		if (ans >= mod)
			ans -= mod;

		return modulo(ans);
	}

	modulo &operator+=(const modulo &rhs)
	{
		x += rhs.x;

		if (x >= mod)
			x -= mod;

		return *this;
	}

	modulo operator-() const
	{
		return modulo(x == 0 ? x : mod - x);
	}

	modulo operator-(const modulo &rhs) const
	{
		return modulo(x < rhs.x ? x - rhs.x + mod : x - rhs.x);
	}

	modulo &operator-=(const modulo &rhs)
	{
		if (x < rhs.x)
			x += mod;

		x -= rhs.x;

		return *this;
	}

	modulo operator*(const modulo &rhs) const
	{
		return modulo(x * (ull) rhs.x);
	}

	modulo &operator*=(const modulo &rhs)
	{
		x = x * (ull) rhs.x % mod;
		return *this;
	}
};

constexpr unsigned mod = 998244353;

using mod_t = modulo<mod>;

template<unsigned mod>
static auto &operator<<(ostream &cout, const modulo<mod> &h)
{
	return cout << unsigned(h);
}

template<unsigned mod>
static auto &operator>>(istream &cin, modulo<mod> &h)
{
	return cin >> h.x;
}


template<class T>
class treap
{
	struct node
	{
		using nodeptr = shared_ptr<node>;

		const T x;
		const T laz;
		const nodeptr l, r;
		const size_t sz;
		const T sum;

		node() : x(), laz(), l(), r(), sz(1), sum()
		{}

		explicit node(const T &x, const T &laz = T{}, const nodeptr &l = nullptr, const nodeptr &r = nullptr) :
				x(x), laz(laz), l(l), r(r),
				sz(get_size(l) + 1 + get_size(r)),
				sum(get_sum(l) + x + get_sum(r) + (laz * T((ull) sz)))
		{}
	};

	using nodeptr = typename node::nodeptr;

	template<class ...Types>
	static nodeptr make_node(Types &&... items)
	{
		dummy_alloc<byte> dal;

		return allocate_shared<node, decltype(dal)>(dal, forward<Types>(items)...);
	}

	static nodeptr add(const nodeptr &h, const T &val)
	{
		if (h == nullptr || val == T{})
			return h;
		return make_node(h->x, h->laz + val, h->l, h->r);
	}

	static nodeptr push(const nodeptr &h)
	{
		if (h == nullptr || h->laz == T{})
			return h;
		return make_node(h->x + h->laz, T{}, add(h->l, h->laz), add(h->r, h->laz));
	}

	static auto get_size(const nodeptr &h)
	{
		return h == nullptr ? size_t{} : h->sz;
	}

	static T get_sum(const nodeptr &h)
	{
		return h == nullptr ? T{} : h->sum;
	}

	static nodeptr merge(const nodeptr &le, const nodeptr &ri)
	{
		if (le == nullptr)
			return ri;
		if (ri == nullptr)
			return le;

		if (uniform_int_distribution<size_t>{0, get_size(le) + get_size(ri) - 1}(mt) < get_size(le))
			return make_node(le->x, le->laz, le->l, merge(le->r, add(ri, -le->laz)));
		else
			return make_node(ri->x, ri->laz, merge(add(le, -ri->laz), ri->l), ri->r);
	}

	template<class F>
	static pair<nodeptr, nodeptr> split(const nodeptr &h, F &&fn)
	{
		if (h == nullptr)
			return {nullptr, nullptr};

		if (auto q = push(h); fn(q))
		{
			auto[le, ri] = split(q->r, forward<F>(fn));

			return {make_node(q->x, T{}, q->l, move(le)), move(ri)};
		}
		else
		{
			auto[le, ri] = split(q->l, forward<F>(fn));

			return {move(le), make_node(q->x, T{}, move(ri), q->r)};
		}
	}

	static nodeptr build(size_t n)
	{
		static nodeptr garb = nullptr;

		while (get_size(garb) < n)
			garb = make_node(T{}, T{}, garb, garb);

		return split_at_size(garb, n).first;
	}

	static auto split_at_size(const nodeptr &h, size_t sz)
	{
		auto cmp = [&sz](const nodeptr &h)
		{
			if (auto ind = get_size(h->l); ind < sz)
			{
				sz -= ind + 1;

				return true;
			}
			else
				return false;
		};

		return split(h, cmp);
	}

	class iterator
	{
		vector<nodeptr> path;
		vector<T> sum = {T{}};

		bool push_back(nodeptr val)
		{
			if (val == nullptr)
				return false;

			sum.push_back(sum.back() + val->laz);
			path.push_back(val);

			return true;
		}

		void pop_back() noexcept
		{
			sum.pop_back();
			path.pop_back();
		}

		void move_left()
		{
			if (path.empty())
				return;

			while (push_back(path.back()->l));
		}

	public:
		explicit iterator(const nodeptr &root = nullptr)
		{
			if (push_back(root))
				move_left();
		}

		bool operator==(const iterator &rhs) const
		{
			return path == rhs.path;
		}

		bool operator!=(const iterator &rhs) const
		{
			return path != rhs.path;
		}

		T operator*() const
		{
			return path.back()->x + sum.back();
		}

		iterator &operator++()
		{
			if (auto nxt = path.back()->r; nxt != nullptr)
			{
				sum.back() += nxt->laz;
				path.back() = nxt;

				move_left();
			}
			else
				pop_back();

			return *this;
		}

		iterator operator++(int)
		{
			auto mem = *this;

			++*this;

			return mem;
		}
	};

	nodeptr root;

public:
	iterator begin()
	{
		return iterator(root);
	}

	iterator end()
	{
		return iterator();
	}

	explicit treap(size_t n = 0, const T &x = T{}) : root(build(n))
	{
		add(x);
	}

	void merge(const treap &rhs)
	{
		root = merge(root, rhs.root);
	}

	void resize(size_t sz)
	{
		if (sz < size())
			root = split_at_size(root, sz).first;
		else
			root = merge(root, build(sz - size()));
	}

	[[nodiscard]] auto sum() const
	{
		return get_sum(root);
	}

	[[nodiscard]] auto size() const
	{
		return get_size(root);
	}

	void swap(treap &rhs)
	{
		root.swap(rhs.root);
	}

	void add(const T &val)
	{
		root = add(root, val);
	}
};


template<class T, class Alloc>
auto &operator>>(istream &cin, vector<T, Alloc> &arr)
{
	copy_n(istream_iterator<T>(cin), arr.size(), arr.begin());

	return cin;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	cin >> arr;

	treap<mod_t> pos(arr.front(), mod_t(1u)), neg(arr.front(), mod_t(mod - 1u));

	for (auto it: arr | views::drop(1))
	{
		auto sum = pos.sum();

		pos.resize(it);
		neg.resize(it);

		pos.swap(neg);

		pos.add(sum);
		neg.add(-sum);
	}

	cout << pos.sum() << endl;
}


void gen(ostream &cout = std::cout)
{
	constexpr int n = 2e5;

	cout << n << endl;

	uniform_int_distribution<int> uid(1, 1e9);

	for ([[maybe_unused]] auto it: ranges::iota_view(1, n))
		cout << uid(mt) << ' ';
	cout << 1 << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	stringstream ss;

	gen(ss);

	solve(ss);

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}