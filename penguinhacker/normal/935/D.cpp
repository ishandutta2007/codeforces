#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD=1e9+7;

ll binPow(ll b, ll p=MOD-2) {
	ll res=1;
	while(p>0) {
		if (p&1)
			res=res*b%MOD;
		b=b*b%MOD;
		p>>=1;
	}
	return res;
}

int n, m, a[100000], b[100000];

ll solve(int p=0) {
	ll res=0;
	for (int i=p; i<n; ++i) {
		//cout << i << "pp\n";
		if (a[i]>0&&b[i]>0) {
			if (a[i]!=b[i]) {
				//cout << (a[i]>b[i]) << "   A";
				return a[i]>b[i];
			}
		}
		else if (a[i]==0&&b[i]>0) {
			res=(m-b[i])*binPow(m)%MOD;
			res+=binPow(m)*solve(i+1);
			break;
		}
		else if (a[i]>0&&b[i]==0) {
			res=(a[i]-1)*binPow(m)%MOD;
			res+=binPow(m)*solve(i+1);
			break;
		}
		else if (a[i]==0&&b[i]==0) {
			res=(m-1)*binPow(2*m)%MOD;
			res+=binPow(m)*solve(i+1);
			break;
		}
	}
	return res%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	cout << solve() << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/