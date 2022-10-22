#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;
int n, m, d[20][50000], cnt[23];
ll ans, iv[21], f[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> d[i][j];
	f[1]=iv[1]=1;
	for (int i=2; i<=n; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
	}
	for (int i=0; i<m; ++i) {
		memset(cnt, 0, sizeof(cnt));
		for (int j=0; j<n; ++j)
			++cnt[d[j][i]];
		ll c=1;
		for (int j=n+1; j>1; --j) {
			cnt[j]+=cnt[j+1];
			if (cnt[j]==0) {
				c=0;
				break;
			}
			c=c*cnt[j]%M;
			--cnt[j];
		}
		ans=(ans+f[n]-c+M)%M;
	}
	for (int i=2; i<=n; ++i)
		ans=ans*iv[i]%M;
	cout << ans;
	return 0;
}