#include <bits/stdc++.h>
#define pb emplace_back
#define int long long
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
	int n, k;
	cin >> n >> k;
	if(k == 1ll)
		cout << 0;
	else if(n == 1ll)
		cout << 0;
	else {
		if((n + 1ll) == k)
			cout << ((k-1ll)/2ll);
		else if((2 * n - 1ll) < k)
			cout << 0;
		else if((n + 1ll) > k)
			cout << ((k - 1ll) / 2ll);
		else
			cout << (n - (k / 2ll));
	}
}