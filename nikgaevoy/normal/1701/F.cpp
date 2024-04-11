#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class K, class V, V one = V{}>
class treap
{
	struct node
	{
		using nodeptr = unique_ptr<node>;

		nodeptr l, r;
		unsigned y;
		K key;
		V val, laz, sum;

	public:
		explicit node(K key, V val = {}) : key(key), val(val), laz(one), sum(val), y(mt()), l(nullptr), r(nullptr)
		{}
	};

	using nodeptr = typename node::nodeptr;

	static void push(const nodeptr &h)
	{
		if (h != nullptr)
		{
			h->val *= h->laz;
			h->sum *= h->laz;

			if (h->l != nullptr)
				h->l->laz *= h->laz;
			if (h->r != nullptr)
				h->r->laz *= h->laz;

			h->laz = one;
		}
	}

	static void upd(const nodeptr &h)
	{
		push(h);

		if (h != nullptr)
		{
			push(h->l);
			push(h->r);

			h->sum = get_sum(h->l) + h->val + get_sum(h->r);
		}
	}


	static V get_sum(const nodeptr &h)
	{
		push(h);
		return h == nullptr ? V{} : h->sum;
	}


	static nodeptr merge(nodeptr &&le, nodeptr &&ri)
	{
		if (le == nullptr)
			return move(ri);
		if (ri == nullptr)
			return move(le);

		if (le->y < ri->y)
		{
			push(le);
			auto tmp = merge(move(le->r), move(ri));
			le->r = move(tmp);
			upd(le);

			return move(le);
		}
		else
		{
			push(ri);
			auto tmp = merge(move(le), move(ri->l));
			ri->l = move(tmp);
			upd(ri);

			return move(ri);
		}
	}


	template<class F>
	static pair<nodeptr, nodeptr> split(nodeptr &&h, F &&fn)
	{
		if (h == nullptr)
			return {nullptr, nullptr};

		push(h);

		if (fn(h))
		{
			auto [le, ri] = split(move(h->r), forward<F>(fn));
			h->r = move(le);

			upd(h);

			return {move(h), move(ri)};
		}
		else
		{
			auto [le, ri] = split(move(h->l), forward<F>(fn));
			h->l = move(ri);

			upd(h);

			return {move(le), move(h)};
		}
	}

	nodeptr root = nullptr;

public:
	void insert(K key, V val)
	{
		auto [le, ri] = split(move(root), [&](const nodeptr &h)
		{
			return h->key < key;
		});

		root = merge(merge(move(le), make_unique<node>(key, val)), move(ri));
	}


	void erase(K key)
	{
		auto [le, tmp] = split(move(root), [&](const nodeptr &h)
		{
			return h->key < key;
		});
		auto [mi, ri] = split(move(tmp), [&](const nodeptr &h)
		{
			return h->key <= key;
		});

		assert(mi != nullptr);

		root = merge(move(le), move(ri));
	}


	V segsum(K l, K r)
	{
		auto [le, tmp] = split(move(root), [&](const nodeptr &h)
		{
			return h->key < l;
		});
		auto [mi, ri] = split(move(tmp), [&](const nodeptr &h)
		{
			return h->key < r;
		});

		auto ans = get_sum(mi);

		root = merge(move(le), merge(move(mi), move(ri)));

		return ans;
	}


	void segmul(V x, K l, K r)
	{
		auto [le, tmp] = split(move(root), [&](const nodeptr &h)
		{
			return h->key < l;
		});
		auto [mi, ri] = split(move(tmp), [&](const nodeptr &h)
		{
			return h->key < r;
		});

		if (mi != nullptr)
			mi->laz *= x;

		root = merge(move(le), merge(move(mi), move(ri)));
	}
};


struct segadd
{
	ll x, sz;

	constexpr explicit segadd(ll x = 0, ll sz = 0) : x(x), sz(sz)
	{}

	constexpr segadd operator+(const segadd &rhs) const
	{
		return segadd{x + rhs.x, sz + rhs.sz};
	}

	constexpr segadd &operator*=(const segadd &rhs)
	{
		assert(rhs.sz == 1);

		x += sz * rhs.x;

		return *this;
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int q, d;

	cin >> q >> d;
	d++;

	vector<int> arr(q);

	for (auto &it: arr)
		cin >> it;

	treap<int, segadd, segadd{0, 1}> tr;
	set<int> st;
	ll ans = 0;

	for (auto it: arr)
	{
		if (st.insert(it).second)
		{
			auto fi = tr.segsum(it, it + d).sz;

			ans += fi * (fi - 1ll) / 2;

			auto se = tr.segsum(it - d + 1, it).x;

			ans += se;

			tr.segmul(segadd{1, 1}, it - d + 1, it);
			tr.insert(it, segadd{fi, 1});
		}
		else
		{
			st.erase(it);

			auto val = tr.segsum(it, it + 1);

			assert(val.sz == 1);

			ans -= val.x * (val.x - 1ll) / 2;

			tr.erase(it);
			tr.segmul(segadd{-1, 1}, it - d + 1, it);

			auto se = tr.segsum(it - d + 1, it).x;

			ans -= se;
		}

		cout << ans << '\n';
	}
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

	cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}