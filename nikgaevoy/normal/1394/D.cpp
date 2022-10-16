#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


class slv
{
	const vector<vector<int>> gr;
	const vector<int> t, dis;
	vector<bool> used;
	array<vector<ll>, 2> dp;


	ll foo(const int v, const int p = -1, const int add = 0)
	{
		used[v] = true;

		auto &q = dp[max(0, add)][v];

		if (q == -1)
		{
			vector<pair<ll, ll>> ch;
			ch.reserve(gr[v].size());

			for (auto it : gr[v])
				if (it != p)
					ch.emplace_back(foo(it, v, -1), foo(it, v, 1));

			auto out = max(0, dis[v]);
			auto in = max(0, -dis[v]);

			if (add > 0)
				out++;
			else if (add < 0)
				in++;

			sort(ch.begin(), ch.end(), [](const auto &a, const auto &b)
			{
				return a.second - a.first < b.second - b.first;
			});

			vector<ll> psa(ch.size() + 1), psb(ch.size() + 1);

			for (int i = 1; i < psa.size(); i++)
			{
				psa[i] = psa[i - 1] + ch[i - 1].first;
				psb[i] = psb[i - 1] + ch[i - 1].second;
			}

			for (int split = 0; split <= ch.size(); split++)
			{
				ll ans = psa[split] + (psb.back() - psb[split]);

				ans += t[v] * (ll) min(in + (int) ch.size() - split, out + split);

				q = max(q, ans);
			}
		}

		assert(q >= 0);

		return q;
	}

public:
	slv(const vector<vector<int>> &gr, const vector<int> &t, const vector<int> &dis) : gr(gr), t(t), dis(dis),
	                                                                                   used(gr.size())
	{
		dp[0].assign(gr.size(), -1);
		dp[1].assign(gr.size(), -1);
	}


	ll get_ans()
	{
		ll ans = 0;

		for (int i = 0; i < gr.size(); i++)
			if (!used[i])
				ans += foo(i);

		return ans;
	}
};


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> t(n), h(n);

	for (auto &it : t)
		cin >> it;
	for (auto &it : h)
		cin >> it;

	vector<vector<int>> gr(n);

	for (int i = 1; i < n; i++)
	{
		int a, b;

		cin >> a >> b;
		a--;
		b--;

		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	vector<int> in(gr.size()), out(gr.size());

	for (auto &row : gr)
		sort(row.begin(), row.end(), [&h](int a, int b)
		{
			return h[a] < h[b];
		});

	for (int i = 0; i < in.size(); i++)
	{
		while (in[i] < gr[i].size() && h[gr[i][in[i]]] < h[i])
			in[i]++;
		out[i] = in[i];
		while (out[i] < gr[i].size() && h[gr[i][out[i]]] <= h[i])
			out[i]++;
	}

	ll ans = 0;

	vector<vector<int>> midgr(gr.size());
	vector<int> dis(gr.size());

	for (int i = 0; i < gr.size(); i++)
	{
		midgr[i] = vector<int>(gr[i].begin() + in[i], gr[i].begin() + out[i]);
		ans += gr[i].size() * (ll) t[i];
		ans -= t[i] * (ll) min((int) gr[i].size() - out[i], in[i]);
		dis[i] = (gr[i].size() - out[i]) - in[i];
	}

	auto dif = slv(midgr, t, dis).get_ans();

	assert(dif >= 0);

	cerr << ans << ' ' << dif << endl;

	cout << ans - dif << endl;
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