#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int log2n(int n)
{
	int cn = 0;
	while (n) {
		n >>= 1;
		cn++;
	}
	return cn;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
#ifdef PIYUSH_HOME
	I_O;
#else
#define print(...) 0
#endif
	int n; cin >> n;
	cout << log2n(n);
}