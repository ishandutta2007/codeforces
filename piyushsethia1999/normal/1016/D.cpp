#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	int n; cin >> n;
	int m; cin >> m;
	std::vector<std::vector<ll> > re(n, std::vector<ll> (m, 0));
	ll ta = 0;
	for (int i = 0; i < n; ++i) {
		cin >> re[i][0];
		ta ^= re[i][0];
	}
	ll tb = 0;
	ll a;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		re[0][i] ^= a;
		tb ^= a;
	}
	if (tb != ta) {
		cout << "NO";
		exit(0);
	}
	re[0][0] ^= ta;
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cout << re[i][j] << "\n "[j != m-1];
}