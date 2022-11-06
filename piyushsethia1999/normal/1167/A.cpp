#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t; cin >> t;
	while (t--)	{
		int n; cin >> n;
		string s; cin >> s;
		bool f = true;
		for (int i = 0; i <= n - 11; ++i) {
			if (s[i] == '8') f = false; 
		}
		if (!f) {
			cout << "YES\n";
		} else
			cout << "NO\n";
	}
}