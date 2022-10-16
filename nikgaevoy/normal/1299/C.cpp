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

	vector<pair<ll, ll>> ps(arr.size() + 1);

	for (int i = 1; i < ps.size(); i++)
	{
		ps[i].first = i;
		ps[i].second = ps[i - 1].second + arr[i - 1];
	}

	vector<int> ch = {(int) ps.size() - 1};
	vector<int> moves(arr.size());

	for (int i = (int) ps.size() - 2; i >= 0; i--)
	{
		while (ch.size() > 1)
		{
			auto j = ch.back();
			auto k = ch[ch.size() - 2];

			if (ps[i].second * (ps[k].first - ps[j].first) + ps[k].second * (ps[j].first - ps[i].first) <=
			    ps[j].second * (ps[k].first - ps[i].first))
				ch.pop_back();
			else
				break;
		}

		moves[i] = ch.back() - i;
		ch.push_back(i);
	}

	cout << fixed << setprecision(10);

	int cur = 0;

	while (cur < arr.size())
	{
		auto nxt = cur + moves[cur];

		auto val = (ps[nxt].second - ps[cur].second) / (long double) moves[cur];

		for (int i = 0; i < moves[cur]; i++)
			cout << val << '\n';

		cur = nxt;
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

	cout << "clock: " << (clock() - st) / (double) CLOCKS_PER_SEC << endl;
#else
	solve();
#endif

	return 0;
}