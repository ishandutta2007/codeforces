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
	int k; cin >> k;
	int a; cin >> a;
	int b; cin >> b;
	int y = (a / k) + (b / k);
	if (a == 0 && b == 0)
		cout << 0;
	else if (((a / k) == 0 && b % k != 0) || ((b / k) == 0 && a % k != 0))
		cout << -1;
	else if (y == 0)
		cout << -1;
	else
		cout << y;
}