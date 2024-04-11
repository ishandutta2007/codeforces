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

	sort (arr.begin (), arr.end ());

	int cnt = count (arr.begin (), arr.end (), 1);

	if (cnt % 2 == 0)
		swap (arr.front (), arr.back ());

	if (n > 1 && arr[1] == 2 && arr[0] == 1)
		swap (arr[0], arr[1]);

	for (auto it : arr)
		cout << it << ' ';
	cout << endl;
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