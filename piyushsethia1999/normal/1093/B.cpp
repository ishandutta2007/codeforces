#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int a[26] = {0};
		int y = 0;
		a[s[0] - 'a']++;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != s[i - 1])
				y = 1;
			a[s[i] - 'a']++;
		}
		if (y == 0)
		{
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < a[i]; ++j)
				cout << (char)(i + 'a');
		cout << "\n";
	}
}