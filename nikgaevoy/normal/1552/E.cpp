#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
mt19937 mt(736);
#else
mt19937 mt(time(nullptr));
#endif // LOCAL


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<int> arr(n * k);

	for (auto &it : arr)
	{
		cin >> it;
		it--;
	}

	vector<vector<int>> col(n);

	for (int j = 0; j < arr.size(); j++)
		col[arr[j]].push_back(j);

	const int bnd = (n + k - 2) / (k - 1);

	cerr << bnd << endl;

	vector<int> cnt(arr.size());

	auto paint = [&cnt](int a, int b, int d = 1)
	{
		for (int t = a; t <= b; t++)
			cnt[t] += d;
	};

	vector<pair<int, int>> ans;

	priority_queue<pair<int, int>> right;

	vector<vector<int>> wait(arr.size());

	for (int j = 0; j < col.size(); j++)
	{
		ans.emplace_back(col[j][0], col[j][1]);
		wait[ans.back().first].push_back(j);

		paint(ans.back().first, ans.back().second);
	}

	vector<int> ind(col.size());

	for (int j = 0; j < arr.size(); j++)
	{
		for (auto it : wait[j])
			right.emplace(ans[it].second, it);
		wait[j].clear();

		while (cnt[j] > bnd)
		{
			auto[r, q] = right.top();
			right.pop();

			assert(r >= j);

			if (ind[q] + 2 != col[q].size())
			{
				paint(ans[q].first, ans[q].second, -1);
				ind[q]++;
				ans[q] = {col[q][ind[q]], col[q][ind[q] + 1]};
				paint(ans[q].first, ans[q].second);

				if (ans[q].first <= j)
					right.emplace(ans[q].second, q);
				else
					wait[ans[q].first].push_back(q);
			}
		}
	}

	for (auto[a, b] : ans)
		cout << a + 1 << ' ' << b + 1 << endl;
}


void gen(ostream &cout = std::cout)
{
	const int n = 100, k = 10;

	vector<int> arr(n * k);

	for (int i = 0; i < arr.size(); i++)
		arr[i] = i / k + 1;

	shuffle(arr.begin(), arr.end(), mt);

	cout << n << ' ' << k << endl;

	for (auto it : arr)
		cout << it << ' ' << endl;
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

	for (int i = 0; i < 10; i++)
	{
		stringstream ss, out;

		gen(ss);

		solve(ss, out);
	}

	cout << setprecision((int) floor(log10(chrono::steady_clock::duration::period::den)));
	cout << "clock: " << chrono::duration<double>(chrono::steady_clock::now() - st).count() << endl;
#else
	solve();
#endif

	return 0;
}