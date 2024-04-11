#include <bits/stdc++.h>


using namespace std;


using ll = long long;


mt19937 mt(736);


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr(n);

	for (auto &it : arr)
		cin >> it;

	sort(arr.begin(), arr.end());

	vector<pair<int, int>> cnt;

	for (int l = 0, r; l < arr.size(); l = r)
	{
		for (r = l; r < arr.size() && arr[r] == arr[l]; r++);

		cnt.emplace_back(r - l, arr[l]);
	}

	sort(cnt.begin(), cnt.end());

	vector<int> ps(cnt.size() + 1);

	for (int i = 1; i < ps.size(); i++)
		ps[i] = ps[i - 1] + cnt[i - 1].first;

	int w = 0, h = 0, cur = 0;

	for (int ss = 1; ss * (ll) ss <= arr.size(); ss++)
	{
		while (cur < cnt.size() && cnt[cur].first <= ss)
			cur++;

		int area = ps[cur] + (cnt.size() - cur) * ss;
		int rp = area / ss;

		area = ss * rp;

		if (ss <= rp && w * h < area)
		{
			h = ss;
			w = rp;
		}
	}

	cout << w * h << endl;
	cout << h << ' ' << w << endl;

	for (auto &it : cnt)
		it.first = min(it.first, h);

	vector<vector<int>> ans(h, vector<int>(w, -1));

	int x = 0, y = 0;

	reverse(cnt.begin(), cnt.end());

	for (auto it : cnt)
	{
		for (int i = 0; x < w && i < it.first; i++)
		{
			ans[y][x] = it.second;

			y++;
			if (y == h)
			{
				y = 0;
				x++;
			}
		}
	}

	assert(x == w);

	for (int i = 0; i < ans.size(); i++)
		rotate(ans[i].begin(), ans[i].end() - i, ans[i].end());

	for (const auto &row : ans)
	{
		for (auto it : row)
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
	auto st = clock();

	ifstream fin("../input.txt");

	solve(fin);

	cout << "clock: " << setprecision(4) << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}