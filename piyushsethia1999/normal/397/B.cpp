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
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int l; cin >> l;
		int r; cin >> r;
		int p = n % l;
		int q = n / l;
		if((r - l) * q >= p)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}