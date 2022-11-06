#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	ll mod = 1000000007;
	int n;
	cin >> n;
	std::vector<std::vector<ll> > c(n+1, std::vector<ll>(n+1, 1));
	for (int i = 2; i < n+1; ++i)
		for (int j = 1; j < i; ++j) {
			c[i][j] = c[i-1][j] + c[i-1][j-1];
			if(c[i][j] > mod)
				c[i][j] -= mod;
		}
	print(c);
	std::vector<int> a(10);
	for (int i = 0; i < 10; ++i)
		cin >> a[i];
	std::vector<std::vector<ll> > res(n+1, std::vector<ll> (10, 0));
	for (int i = a[9]; i < n+1; ++i)
		res[i][9] = 1;
	for (int i = 8; i >= 1 ; --i) {
		print(res);
		for (int j = 0; j < n+1; ++j)
			for (int k = a[i]; k < n+1; ++k)
				if(j-k >= 0)
					res[j][i] = (res[j][i] + res[j-k][i+1]*c[j][j-k])%mod;
	}
	print(res);
	for (int j = 0; j < n+1; ++j)
		for (int k = a[0]; k < n+1; ++k)
			if(j-k > 0)
				res[j][0] = (res[j][0] + res[j-k][1]*c[j-1][j-k-1])%mod;
	print(res);
	ll r = 0;
	for (int i = 0; i < n+1; ++i)
		r += res[i][0];
	cout << (r%mod);
}