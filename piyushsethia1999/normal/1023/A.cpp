#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;


int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
	I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	int m; cin >> m;
	string s; cin >> s;
	string t; cin >> t;
	// print(s, t, n, m);
	int pos = -1;
	bool ans = false;
	for (int i = 0; i < n; ++i) {
		if(s[i] == '*')
			pos = i;
	}
	// print(pos);
	if(pos == -1) {
		if(s == t) {
			ans = true;
		}
	}
	else
	{
		// print("Iam here");
		bool f = false;
		if((n - 1) > m)
			f = true;
		for (int i = 0; i < pos && !f; ++i)
			if(s[i] != t[i])
				f = true;
		for (int i = 0; i < (n - pos - 1) && !f; ++i)
			if(i <= (m - 1) && s[n - 1 - i] != t[m - i - 1])
				f = true;
		if(!f)
			ans = true;
	}
	if(ans)
		cout << "YES";
	else
		cout << "NO";
}