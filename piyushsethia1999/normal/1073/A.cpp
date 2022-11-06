#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int l; cin >> l;
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n - 1; ++i)
	{
		if (s[i] != s[i + 1])
		{
			cout << "YES\n";
			cout << s[i] << s[i + 1];
			return 0;
		}
	}
	cout << "NO";
}