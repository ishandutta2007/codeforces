#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;

	cin >> n;

	vector<int> arr (n);

	for (auto &it : arr)
		cin >> it;

	arr.insert(arr.end (), arr.begin(), arr.end ());

	int ans = 0;

	for (int l = 0, r; l < arr.size (); l = r + 1)
	{
		for (r = l; r < arr.size () && arr[r] == 1; r++);

		ans = max (ans, r - l);
	}

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