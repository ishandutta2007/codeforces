#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=(int)3e5+1;
int n=1, q, a[mxN], c[mxN], d[mxN], anc[mxN][19];

int lift(int u, int x) {
	for (int i=0; i<19; ++i)
		if (x>>i&1)
			u=anc[u][i];
	return u;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> q >> a[0] >> c[0];
	for (int i=1; i<=q; ++i) {
		int t;
		cin >> t;
		if (t==1) {
			cin >> anc[i][0] >> a[i] >> c[i];
			d[i]=d[anc[i][0]]+1;
			for (int j=1; j<19; ++j)
				anc[i][j]=anc[anc[i][j-1]][j-1];
		} else {
			int u, w;
			cin >> u >> w;
			ll ans=0, cnt=0;
			int v=u;
			for (int i=18; ~i; --i)
				if (a[anc[v][i]])
					v=anc[v][i];
			while(1) {
				if (a[v]>=w) {
					ans+=(ll)c[v]*w;
					a[v]-=w, cnt+=w;
					break;
				}
				ans+=(ll)a[v]*c[v];
				w-=a[v], cnt+=a[v];
				a[v]=0;
				if (u==v)
					break;
				v=lift(u, d[u]-d[v]-1);
			}
			cout << cnt << " " << ans << endl;
		}
	}
	return 0;
}