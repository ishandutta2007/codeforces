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
	int k; cin >> k;
	string s; cin >> s;
	int i, cnt;
	for (i = 0, cnt = 0; i < n && cnt < (k/2); ++i)
	{
		if(s[i] == '(')
			cnt++;
		cout << s[i];
	}
	for (; i < k; ++i)
		cout << ")";
}