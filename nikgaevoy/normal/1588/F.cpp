#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;


template<class T>
class segtree
{
	vector<T> arr;

public:
	explicit segtree(size_t n = 0) : arr(2 * n)
	{}

	template<class It>
	explicit segtree(It be, It en) : arr(2 * distance(be, en))
	{
		copy(be, en, arr.begin() + arr.size() / 2);

		for (auto j = ssize(arr) / 2 - 1; j > 0; j--)
			arr[j] = arr[2 * j] + arr[2 * j + 1];
	}

	void add(size_t pos, const T &x)
	{
		pos += arr.size() / 2;

		while (pos > 0)
		{
			arr[pos] += x;
			pos /= 2;
		}
	}

	[[nodiscard]] T operator()(size_t l, size_t r) const
	{
		l += arr.size() / 2;
		r += arr.size() / 2;

		T le{}, ri{};

		while (l < r)
		{
			if (l % 2 != 0)
				le += arr[l++];
			if (r % 2 != 0)
				ri = arr[--r] + ri;

			l /= 2;
			r /= 2;
		}

		return le + ri;
	}
};


template<class T, ssize_t block_size>
class sqrt_dec
{
	vector<T> arr, blocks;

public:
	explicit sqrt_dec(ssize_t n = 0) : arr(n), blocks((n + block_size - 1) / block_size)
	{}

	template<class It>
	explicit sqrt_dec(It be, It en) : arr(distance(be, en)), blocks((distance(be, en) + block_size - 1) / block_size)
	{
		for (int j = 0; be != en; ++be, j++)
			blocks[j / block_size] += (arr[j] = *be);
	}

	void add(size_t pos, const T &x)
	{
		arr[pos] += x;
		blocks[pos / block_size] += x;
	}

	[[nodiscard]] T operator()(size_t l, size_t r) const
	{
		T sum{};

		while (l < r && l % block_size != 0)
			sum += arr[l++];
		while (l < r && r % block_size != 0)
			sum += arr[--r];
		l /= block_size;
		r /= block_size;
		while (l < r)
			sum += blocks[l++];

		return sum;
	}
};


template<ssize_t, class>
class cycler;


class block
{
	ll laz;
	vector<int> arr;
	int first, last;

public:
	template<class It>
	block(It be, It en) : laz(0), arr(be, en), first(be == en ? -1 : *be), last(be == en ? -1 : *(en - 1))
	{
		sort(arr.begin(), arr.end());
	}

	template<ssize_t block_size, class ST>
	block(cycler<block_size, ST> &super, block &&a, block &&b) : laz(0), arr(a.arr.size() + b.arr.size()),
	                                                             first(a.first),
	                                                             last(b.last)
	{
		a.push(super);
		b.push(super);

		assert(a.laz == 0 && b.laz == 0);

		if (first == -1)
			first = b.first;
		if (last == -1)
			last = a.last;

		merge(a.arr.begin(), a.arr.end(), b.arr.begin(), b.arr.end(), arr.begin());
	}

	template<ssize_t block_size, class ST, class F>
	static pair<block, block> split(cycler<block_size, ST> &super, block &&bl, const vector<int> &perm, F &&fn)
	{
		bl.push(super);

		assert(bl.laz == 0);

		vector<int> tmp;
		tmp.reserve(bl.arr.size());

		for (auto i = bl.first; tmp.size() < bl.arr.size(); i = perm[i])
			tmp.push_back(i);

		assert(tmp.empty() || tmp.back() == bl.last);

		auto mid = find_if(tmp.begin(), tmp.end(), forward<F>(fn));

		return {block(tmp.begin(), mid), block(mid, tmp.end())};
	}

	[[nodiscard]] const vector<int> &get_arr() const
	{
		return arr;
	}

	[[nodiscard]] auto size() const
	{
		return arr.size();
	}

	[[nodiscard]] auto empty() const
	{
		return arr.empty();
	}

	[[nodiscard]] ll ask(int l, int r) const
	{
		return laz * (lower_bound(arr.begin(), arr.end(), r) - lower_bound(arr.begin(), arr.end(), l));
	}

	void add(ll x)
	{
		laz += x;
	}

	void fast_push(auto &val)
	{
		if (laz != 0)
		{
			for (auto it: arr)
				val.add(it, laz);
			laz = 0;
		}
	}

	template<ssize_t block_size, class ST>
	void push(cycler<block_size, ST> &super)
	{
		fast_push(super.st);

		if (!empty())
			super.ind_long.erase(super.block_it[first]);
	}

	[[nodiscard]] auto front() const
	{
		return first;
	}

	[[nodiscard]] auto back() const
	{
		return last;
	}
};


namespace std
{
	template<>
	struct hash<list<block>::iterator>
	{
		auto operator()(const list<block>::iterator &q) const noexcept
		{
			return hash<block *>{}(&*q);
		}
	};
}


template<ssize_t block_size, class ST>
class cycler
{
	friend block;

	ST &st;

	vector<int> &perm;
	vector<int> inv_perm;

	list<block> blocks;

	unordered_set<typename decltype(blocks)::iterator> ind_long;

	vector<typename decltype(blocks)::iterator> block_it;

public:
	cycler(ST &st, vector<int> &perm) : st(st), perm(perm), inv_perm(perm.size()), block_it(perm.size())
	{
		for (int j = 0; j < perm.size(); j++)
			inv_perm[perm[j]] = j;

		vector<bool> used(perm.size());

		for (int i = 0; i < perm.size(); i++)
			if (!used[i])
			{
				vector<int> cyc;

				for (auto j = i; !used[j]; j = perm[j])
				{
					cyc.push_back(j);
					used[j] = true;
				}

				if (cyc.size() < block_size)
				{
					blocks.emplace_back(cyc.begin(), cyc.end());
				}
				else
				{
					for (ssize_t j = 0; j < ssize(cyc); j += block_size)
					{
						blocks.emplace_back(cyc.begin() + j, cyc.begin() + min(j + block_size, ssize(cyc)));
						ind_long.insert(--blocks.end());
					}
				}
			}

		for (auto bl_it = blocks.begin(); bl_it != blocks.end(); ++bl_it)
			for (auto it: bl_it->get_arr())
				block_it[it] = bl_it;
	}


	void add(int v, ll x)
	{
		const auto bi = block_it[v];

		if (perm[bi->back()] == bi->front()) // short
		{
			bi->add(x);
			bi->fast_push(st);
		}
		else // long
		{
			auto get_next = [&](auto it)
			{
				return block_it[perm[it->back()]];
			};

			auto q = bi;

			do
			{
				q->add(x);
				ind_long.insert(q);
				q = get_next(q);
			} while (q != bi);
		}
	}


	ll ask(int l, int r)
	{
		auto ans = st(l, r);

		for (const auto &it: ind_long)
			ans += it->ask(l, r);

		return ans;
	}


	auto reg(block &&bl)
	{
		blocks.push_back(move(bl));
		for (auto it: blocks.back().get_arr())
			block_it[it] = --blocks.end();
		return --blocks.end();
	};


	auto try_merge(decltype(block_it)::value_type a,
	               decltype(block_it)::value_type b) -> pair<bool, typename decltype(block_it)::value_type>
	{
		if (a == b)
			return {false, a};

		if (a->size() + b->size() <= block_size)
		{
			a->push(*this);
			b->push(*this);

			block ba = move(*a);
			block bb = move(*b);

			blocks.erase(a);
			blocks.erase(b);

			return {true, reg(move(block(*this, move(ba), move(bb))))};
		}

		return {false, a};
	}

	void try_merge(decltype(block_it)::value_type bl)
	{
		bl = try_merge(bl, block_it[perm[bl->back()]]).second;
		try_merge(block_it[inv_perm[bl->front()]], bl);
	}


	void recycle(int i, int j)
	{
		auto bi = block_it[i];
		auto bj = block_it[j];

		bi->push(*this);
		bj->push(*this);

		if (bi == bj) // same block
		{
			block bb = move(*bi);
			blocks.erase(bi);
			auto[lb, tmp] = block::split(*this, move(bb), perm, [&](int t)
			{
				return t == perm[i] || t == perm[j];
			});

			assert(tmp.front() == perm[i] || tmp.front() == perm[j]);
			auto val = perm[i] ^ perm[j] ^ tmp.front();

			auto[mb, rb] = block::split(*this, move(tmp), perm, [&](int t)
			{
				return t == val;
			});

			swap(perm[i], perm[j]);
			swap(inv_perm[perm[i]], inv_perm[perm[j]]);

			reg(move(lb));
			reg(move(mb));
			reg(move(rb));

			try_merge(block_it[i]);
			try_merge(block_it[perm[i]]);
			try_merge(block_it[j]);
			try_merge(block_it[perm[j]]);

			return;
		}

		block tbi = move(*bi);
		blocks.erase(bi);
		block tbj = move(*bj);
		blocks.erase(bj);

		auto[lbi, rbi] = block::split(*this, move(tbi), perm, [&](int t)
		{
			return t == perm[i];
		});
		auto[lbj, rbj] = block::split(*this, move(tbj), perm, [&](int t)
		{
			return t == perm[j];
		});

		swap(perm[i], perm[j]);
		swap(inv_perm[perm[i]], inv_perm[perm[j]]);

		reg(move(lbi));
		reg(move(rbi));
		reg(move(lbj));
		reg(move(rbj));

		try_merge(block_it[i]);
		try_merge(block_it[perm[i]]);
		try_merge(block_it[j]);
		try_merge(block_it[perm[j]]);
	}
};


template<ssize_t block_size = 400, ssize_t add_size = 400>
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> arr(n);

	for (auto &it: arr)
		cin >> it;

	sqrt_dec<ll, add_size> st(arr.begin(), arr.end());

	vector<int> perm(n);

	for (auto &it: perm)
	{
		cin >> it;
		it--;
	}

	cycler<block_size, decltype(st)> slv(st, perm);

	int q;

	cin >> q;

	for (auto it: ranges::iota_view(0, q))
	{
		int t;

		cin >> t;

		if (t == 1)
		{
			int l, r;

			cin >> l >> r;
			l--;

			cout << slv.ask(l, r) << '\n';
#ifdef LOCAL
			cout << flush;
#endif
		}
		else if (t == 2)
		{
			int v, x;

			cin >> v >> x;
			v--;

			slv.add(v, x);
		}
		else
		{
			assert(t == 3);

			int i, j;

			cin >> i >> j;
			i--;
			j--;

			if (i != j)
				slv.recycle(i, j);
		}
	}
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<ll> arr(n);

	for (auto &it: arr)
		cin >> it;

	vector<int> perm(n);

	for (auto &it: perm)
	{
		cin >> it;
		it--;
	}

	int q;

	cin >> q;

	for (auto it: ranges::iota_view(0, q))
	{
		int t;

		cin >> t;

		if (t == 1)
		{
			int l, r;

			cin >> l >> r;
			l--;

			cout << accumulate(arr.begin() + l, arr.begin() + r, 0ll) << endl;
		}
		else if (t == 2)
		{
			int v, x;

			cin >> v >> x;
			v--;

			auto u = v;

			do
			{
				arr[u] += x;
				u = perm[u];
			} while (u != v);
		}
		else
		{
			assert(t == 3);

			int i, j;

			cin >> i >> j;
			i--;
			j--;

			swap(perm[i], perm[j]);
		}
	}
}


template<int n, int q>
void gen(ostream &cout = std::cout)
{
	static mt19937_64 mt(736);

	cout << n << endl;

	uniform_int_distribution<int> uid(-10, 10), type(1, 3), vert(1, n);

	for (auto it: ranges::iota_view(0, n))
		cout << uid(mt) << ' ';
	cout << endl;

	vector<int> perm(n);

	iota(perm.begin(), perm.end(), 1);
	shuffle(perm.begin(), perm.end(), mt);

	for (auto it: perm)
		cout << it << ' ';
	cout << endl;

	cout << q << endl;

	for (auto it: ranges::iota_view(0, q))
	{
		auto t = type(mt);

		cout << t << ' ';

		if (t == 1)
		{
			auto l = vert(mt), r = vert(mt);

			if (r < l)
				swap(l, r);

			cout << l << ' ' << r << endl;
		}
		else if (t == 2)
		{
			cout << vert(mt) << ' ' << uid(mt) << endl;
		}
		else
		{
			assert(t == 3);

			cout << vert(mt) << ' ' << vert(mt) << endl;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = chrono::steady_clock::now();

	ifstream fin("../input.txt");

	do
	{
		solve(fin);

		cout << "===" << endl;

		string str;
		while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
	} while (fin);

	stringstream ss, out;

	gen<(int) 2e5, (int) 2e5>(ss);

	solve(ss, out);

	int cnt = 0;

	while (!true)
	{
		stringstream ss, in1, in2, out1, out2;

		gen<4, 3>(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail:\t" << cnt << endl;
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (++cnt % 100 == 0)
			cout << "ok:\t" << cnt << endl;
	}

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}