#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


int up(int n)
{
	int r = 1;

	while (r < n)
		r *= 2;

	return r;
}


class segtree
{
	vector<int> arr;

	[[nodiscard]] int segsum(int l, int r, int cl, int cr, int v) const
	{
		if (r <= cl || cr <= l)
			return 0;
		if (l <= cl && cr <= r)
			return arr[v];

		int ct = (cl + cr) / 2;

		return segsum(l, r, cl, ct, 2 * v) + segsum(l, r, ct, cr, 2 * v + 1);
	}

public:
	segtree(int n = 0) : arr(2 * up(n))
	{}


	void add(int wh, int x)
	{
		wh += (int) arr.size() / 2;

		while (wh > 0)
		{
			arr[wh] += x;
			wh /= 2;
		}
	}


	[[nodiscard]] int segsum(int l, int r) const
	{
		return segsum(l, r, 0, (int) arr.size() / 2, 1);
	}
};


class crucian
{
	struct node
	{
		array<int, 27> nxt;
		int par, link;

		node(int par = -1) : par(par), link(-1)
		{
			fill(nxt.begin(), nxt.end(), -1);
		}
	};

	vector<node> mem;


	void get_ord(vector<pair<int, int>> &segs, vector<int> &ord, int &tim, int v)
	{
		if (v == -1)
			return;

		ord.push_back(v);
		segs[v].first = tim++;

		for (auto it : mem[v].nxt)
			get_ord(segs, ord, tim, it);

		segs[v].second = tim;
	}

public:
	crucian() : mem(1)
	{}


	int move(int v, char ch)
	{
		assert(v < mem.size());

		if (mem[v].nxt[ch - 'a'] == -1)
		{
			mem[v].nxt[ch - 'a'] = mem.size();
			mem.emplace_back(v);
		}

		return mem[v].nxt[ch - 'a'];
	}


	int link_move(int v, int ch, int ind = -1)
	{
		if (v != -1)
		{
			while (mem[v].link != -1 && (mem[v].nxt[ch] == -1 || mem[v].nxt[ch] == ind))
				v = mem[v].link;

			if (mem[v].nxt[ch] != -1 && mem[v].nxt[ch] != ind)
				v = mem[v].nxt[ch];
		}

		return v;
	}


	void build()
	{
		queue<pair<int, int>> q;
		q.emplace(0, -1);

		int cnt = 0;

		while (!q.empty())
		{
			int v = q.front().first;
			int ch = q.front().second;
			q.pop();

			if (v != -1)
			{
				cnt++;

				for (int i = 0; i < mem[v].nxt.size(); i++)
					q.emplace(mem[v].nxt[i], i);

				mem[v].link = link_move(mem[v].par, ch, v);
			}
		}

		assert(cnt == mem.size());
	}


	auto get_ord()
	{
		vector<pair<int, int>> segs(mem.size());
		vector<int> ord;

		int tim = 0;

		get_ord(segs, ord, tim, 0);

		return pair{segs, ord};
	}


	auto get_gr()
	{
		vector<vector<int>> gr(mem.size());

		for (int i = 1; i < mem.size(); i++)
			gr[mem[i].link].push_back(i);

		return gr;
	}
};


void get_ord(const vector<vector<int>> &gr, vector<pair<int, int>> &segs, vector<int> &ord, int &tim, int v)
{
	ord.push_back(v);
	segs[v].first = tim++;

	for (auto it : gr[v])
		get_ord(gr, segs, ord, tim, it);

	segs[v].second = tim;
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	crucian tr;

	vector<int> memval = {0};

	for (int i = 0; i < n; i++)
	{
		int t, v = 0;

		cin >> t;

		if (t == 2)
			cin >> v;

		v = memval[v];

		char ch;

		cin >> ch;

		memval.push_back(tr.move(v, ch));
	}

	int m;

	cin >> m;

	vector<pair<int, int>> queries(m);

	for (auto &it : queries)
	{
		string tmp;

		cin >> it.second >> tmp;
		it.second = memval[it.second];

		int st = 0;

		for (auto ch : tmp)
			st = tr.move(st, ch);

		it.first = st;
	}

	tr.build();

	auto lgr = tr.get_gr();

	vector<pair<int, int>> segs, grsegs(lgr.size());
	vector<int> ord, grord;

	tie(segs, ord) = tr.get_ord();
	int tim = 0;
	get_ord(lgr, grsegs, grord, tim, 0);
	swap(grsegs, segs);
	swap(grord, ord);

	segtree st(tim + 1);

	vector<int> ans(queries.size());
	vector<tuple<int, int, int, int>> sc;

	auto grunord = grord;
	for (int i = 0; i < grord.size(); i++)
		grunord[grord[i]] = i;
	auto unord = ord;
	for (int i = 0; i < ord.size(); i++)
		unord[ord[i]] = i;

	for (int i = 0; i < queries.size(); i++)
	{
		const auto &it = queries[i];
		sc.emplace_back(segs[it.first].first, it.second, i, -1);
		sc.emplace_back(segs[it.first].second, it.second, i, 1);
	}

	sort(sc.begin(), sc.end());

	int cur = 0;

	for (const auto &it : sc)
	{
		int le, to, ind;
		int mult;

		tie(le, to, ind, mult) = it;

		while (cur < le)
		{
			st.add(grsegs[ord[cur]].first, 1);
			st.add(grsegs[ord[cur]].second, -1);
			cur++;
		}

		ans[ind] += mult * st.segsum(0, grunord[to] + 1);
	}

	for (auto it : ans)
		cout << it << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}