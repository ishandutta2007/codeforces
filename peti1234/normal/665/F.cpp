#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, m, k, sum, f[320001], g[320001];
int main(){
	cin >> n, k=pow(n+1, 1.0/3);
	for (m=1; m*m<=n; m++) g[m]=m, f[m]=n/m;
	m--;
	for (ll i=2; i<=m; i++) if (g[i]>g[i-1]) {
        for (ll j=1; j<=min(m, n/i/i); j++) {
            f[j]+=g[i-1];
            if (i*j<=m) f[j]-=f[i*j];
            else f[j]-=g[n/i/j];
        }
        for (ll j=m; j>=i*i; j--) g[j]-=g[j/i]-g[i-1];
	}
	sum=g[k]-1;
	for (ll i=2; i<=m; i++) if (g[i]>g[i-1]) sum+=f[i]-g[i];
	cout << sum << "\n";
}