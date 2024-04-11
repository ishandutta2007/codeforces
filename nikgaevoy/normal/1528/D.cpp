#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

mt19937 mt(736);


template<class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;


template<class T>
T &remin(T &x, const T &y)
{
	return x = min(x, y);
}


void Dijkstra(const vector<vector<pair<int, int>>> &gr, vector<int> &ans, int st)
{
	vector<int> dist(ans.size(), numeric_limits<int>::max());
	dist[st] = 0;

	for (int i = 0; i < gr.size(); i++)
	{
		int best = find(ans.begin(), ans.end(), -1) - ans.begin();

		for (int j = best + 1; j < dist.size(); j++)
			if (ans[j] == -1 && dist[j] < dist[best])
				best = j;

		ans[best] = dist[best];
		auto shift = ans[best] % gr.size();

		for (int cur = 0; cur < gr[best].size(); cur++)
		{
			auto nxt = cur + 1 == gr[best].size() ? 0 : cur + 1;

			auto cnt = gr[best][nxt].first - gr[best][cur].first;

			if (cnt <= 0)
				cnt += gr.size();

			for (int j = 0; j < cnt; j++)
			{
				auto to = (gr[best][cur].first + shift + j) % gr.size();
				remin(dist[to], ans[best] + j + gr[best][cur].second);
			}
		}
	}
}


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;

	cin >> n >> m;

	vector<vector<pair<int, int>>> gr(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		gr[a].emplace_back(b, c);
	}

	for (auto &row : gr)
	{
		sort(row.begin(), row.end());

		vector<bool> bad(row.size());

		vector<pair<int, int>> tmp;

		for (int j = 0; j < bad.size(); j++)
			for (int i = 0; !bad[j] && i < bad.size(); i++)
			{
				auto diff = row[j].first - row[i].first;

				if (diff < 0)
					diff += n;

				bad[j] = diff + row[i].second < row[j].second;
			}

		for (int i = 0; i < bad.size(); i++)
			if (!bad[i])
				tmp.push_back(row[i]);

		row.swap(tmp);
	}

	vector<int> ans(gr.size());

	for (int i = 0; i < n; i++)
	{
		fill(ans.begin(), ans.end(), -1);

		Dijkstra(gr, ans, i);

		for (auto it : ans)
			cout << it << ' ';
		cout << endl;
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

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}