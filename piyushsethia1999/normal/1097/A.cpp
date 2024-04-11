#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	string s; cin >> s;
	vector<string> a(5); for (int o = 0; o < 5; o++) { cin >> a[o]; }
	for (int i = 0; i < 5; ++i)
	{
		if (s[0] == a[i][0] || s[1] == a[i][1])
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}