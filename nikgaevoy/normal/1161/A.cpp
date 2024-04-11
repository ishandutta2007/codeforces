#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;

	cin >> n >> k;

	vector<int> arr(k);

	vector<int> fs(n, -1), ls(n, -1);

	for (int i = 0; i < (int) arr.size(); i++)
	{
		auto &it = arr[i];
		cin >> it;
		it--;
		ls[it] = i;
		if (fs[it] == -1)
			fs[it] = i;
	}

	int ans = 0;

	for (int a = 0; a < n; a++)
		for (int b = max(a - 1, 0); b < n && b <= a + 1; b++)
			if (ls[b] == -1 || ls[a] == -1 || ls[a] < fs[b])
				ans++;

	cout << ans << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;

#ifdef LOCAL
	ifstream fin("../input.txt");

	solve(fin);

	cout << setprecision(4) << "clock: " << clock() / (double) CLOCKS_PER_SEC << endl;
#else
	cout << setprecision(20);

	solve();
#endif

	return 0;
}