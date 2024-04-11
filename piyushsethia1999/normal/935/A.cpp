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
	int cnt = 0;
	for (int i = 1; i < n; ++i)
		if (n % i == 0)
			cnt++;
	cout << cnt;
}