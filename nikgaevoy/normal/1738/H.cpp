#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


class segtree
{
	vector<int> arr;

public:
	explicit segtree(size_t n = 0) : arr(2 * n)
	{}

	void add(ssize_t wh, int x)
	{
		wh += ssize(arr) / 2;

		while (wh > 0)
		{
			arr[wh] += x;
			wh /= 2;
		}
	}

	[[nodiscard]] int segsum(ssize_t l, ssize_t r) const
	{
		l += ssize(arr) / 2;
		r += ssize(arr) / 2;

		int ans = 0;

		while (l < r)
		{
			if (l % 2 != 0)
				ans += arr[l++];
			if (r % 2 != 0)
				ans += arr[--r];

			l /= 2;
			r /= 2;
		}

		return ans;
	}
};


class hld
{
	vector<int> wh, siz, path, par, ord;
	segtree st;

	void build(const vector<vector<int>> &gr, int v, int &t, int pp = 0, int p = 0)
	{
		auto &ind = wh[v];
		ind = t++;
		ord[ind] = v;
		path[ind] = pp;
		par[ind] = p;

		if (!gr[v].empty())
		{
			build(gr, gr[v].front(), t, pp, v);

			for (auto it: gr[v] | views::drop(1))
				build(gr, it, t, t, ind);
		}

		siz[ind] = t - ind;
	}

public:
	hld() = default;

	explicit hld(const vector<vector<int>> &gr, int root = 0) : wh(gr.size()), siz(gr.size()), path(gr.size()),
	                                                            par(gr.size()), ord(gr.size()), st(gr.size())
	{
		int t = 0;
		build(gr, root, t);
		assert(t == ssize(gr));
	}

	void add(int v, int x = 1)
	{
		v = wh[v];

		if (x == -1)
			assert(st.segsum(v, v + 1) > 0);

		st.add(v, x);
	}

	[[nodiscard]] bool blocked(int v) const
	{
		v = wh[v];

		return st.segsum(v, v + siz[v]) > 0;
	}


	int lower_bound(int v, auto &&fn) const
	{
		if (fn(v))
			return v;

		v = wh[v];

		auto ask = [&](int v)
		{
			return fn(ord[v]);
		};

		while (!ask(par[path[v]]))
			v = par[path[v]];

		if (!ask(path[v]))
			return ord[par[path[v]]];

		auto l = path[v];
		auto r = v;

		while (l + 1 < r)
		{
			auto t = midpoint(l, r);

			(ask(t) ? l : r) = t;
		}

		return ord[l];
	}
};


class treert
{
	struct node
	{
		array<int, 26> nxt{};
		int par, link, siz;

		node(int siz, int par, int link) : par(par), link(link == -1 ? 1 : link), siz(siz)
		{
			fill(nxt.begin(), nxt.end(), -1);
		}
	};

	vector<node> mem;
	vector<int> suff, pref;
	int le = 0, ri = 0;
	hld tr;

	template<class It>
	void build(It str, It en, vector<int> &ans)
	{
		auto link_walk = [&](int st, int pos)
		{
			while (pos - 1 - mem[st].siz < 0 || str[pos] != str[pos - 1 - mem[st].siz])
				st = mem[st].link;

			return st;
		};

		for (int i = 0, last = 1; i < distance(str, en); i++)
		{
			last = link_walk(last, i);
			auto ind = str[i] - 'a';

			if (mem[last].nxt[ind] == -1)
			{
				// order is important
				mem.emplace_back(mem[last].siz + 2, last, mem[link_walk(mem[last].link, i)].nxt[ind]);
				mem[last].nxt[ind] = (int) mem.size() - 1;
			}

			last = mem[last].nxt[ind];

			ans[i] = last;
		}
	}

public:
	explicit treert(const string &str = "") : suff(str.size()), pref(str.size())
	{
		mem.emplace_back(-1, -1, 0);
		mem.emplace_back(0, 0, 0);
		mem[0].link = mem[1].link = 0;

		build(str.begin(), str.end(), suff);
		auto sz = mem.size();
		build(str.rbegin(), str.rend(), pref);
		ranges::reverse(pref);
		assert(mem.size() == sz);

		vector<vector<int>> gr(mem.size());

		for (int i = 1; i < ssize(gr); i++)
			gr[mem[i].link].push_back(i);

		vector<int> siz(gr.size(), 1);

		for (auto v: ranges::iota_view(0, ssize(siz)) | views::reverse)
			for (auto it: gr[v])
				siz[v] += siz[it];

		for (auto &row: gr)
			ranges::sort(row, [&siz](int a, int b)
			{
				return siz[a] > siz[b];
			});

		tr = hld(gr);
	}

	bool push()
	{
		auto v = suff[ri];
		ri++;

		v = tr.lower_bound(v, [&](int x)
		{
			return mem[x].siz <= ri - le;
		});

		auto ans = !tr.blocked(v);
		tr.add(v);

		return ans;
	}

	bool pop()
	{
		auto v = pref[le];

		v = tr.lower_bound(v, [&](int x)
		{
			return mem[x].siz <= ri - le;
		});

		assert(tr.blocked(v));

		tr.add(v, -1);
		le++;

		return !tr.blocked(v);
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int q;

	cin >> q;

	vector<char> arr(q);

	for (auto &it: arr)
	{
		string str;

		cin >> str;

		if (str == "push")
			cin >> it;
		else
			assert(str == "pop");
	}

	string str;

	ranges::copy(arr | views::filter([](char ch)
	                                 { return ch != 0; }),
	             back_inserter(str));

	treert tr(str);

	int ans = 0;

	for (auto it: arr)
	{
		if (it)
			ans += tr.push();
		else
			ans -= tr.pop();

		cout << ans << '\n';
	}
}


void stress(istream &cin = std::cin, ostream &cout = std::cout)
{
	solve(cin, cout);
}


void gen(ostream &cout = std::cout)
{
	constexpr int q = 1e6;

	cout << q << endl;

	uniform_int_distribution<char> uid('a', 'z');
	uniform_int_distribution<int> type(0, 1);

	int sz = 0;

	for (auto i: ranges::iota_view(0, q))
	{
		if (sz == 0 || type(mt))
		{
			cout << "push " << uid(mt) << endl;
			sz++;
		}
		else
		{
			cout << "pop" << endl;
			sz--;
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

	gen(ss);

	solve(ss, out);

#ifdef STRESS
	for (int cnt = 1;; cnt++)
	{
		stringstream ss, in1, out1, in2, out2;

		gen(ss);

		in1 << ss.str();
		in2 << ss.str();

		solve(in1, out1);
		stress(in2, out2);

		if (out1.str() != out2.str())
		{
			cout << "fail: " << cnt << endl;
			cout << ss.str();
			cout << "solve:" << endl;
			cout << out1.str();
			cout << "stress:" << endl;
			cout << out2.str();

			break;
		}
		else if (cnt % 100 == 0)
			cout << "ok: " << cnt << endl;
	}
#endif

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}