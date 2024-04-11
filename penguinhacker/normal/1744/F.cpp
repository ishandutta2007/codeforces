#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, p[mxN], pos[mxN];
bool vis[mxN];

ll c(ll x) {
	return x*(x+1)/2;
}

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> p[i];
		pos[p[i]]=i;
		vis[i]=0;
	}
	int mex=0;
	ll ans=0;
	int l, r;
	while(mex<n) {
		if (!mex) {
			l=r=pos[0];
			vis[0]=1;
			mex=1;
		} else if (pos[mex]<l) {
			while(l>pos[mex])
				vis[p[--l]]=1;
		} else if (pos[mex]>r) {
			while(r<pos[mex])
				vis[p[++r]]=1;
		}
		while(mex<n&&vis[mex])
			++mex;
		//cout << mex << endl;
		if (r-l+1>=2*mex+1)
			continue;
		if (l==0&&r==n-1) {
			++ans;
			break;
		}
		int x=pos[mex]<l?l-pos[mex]-1:pos[mex]-r-1;
		int y=pos[mex]<l?n-r-1:l;
		int can=2*mex-(r-l+1);
		//cout << x << " " << y << " " << can << endl;
		if (x>y)
			swap(x, y);
		//cout << x << " " << y << " " << can << endl;
		if (x>=can) {
			ans+=c(can+1);
		} else if (x+y<=can) {
			ans+=(ll)(x+1)*(y+1);
		} else if (y<=can) {
			ans+=(ll)(x+1)*(y+1)-c(x+y-can);
		} else if (can>=x&&can<=y) {
			ans+=c(x+1)+(ll)(x+1)*(can-x);
		} else {
			assert(0);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}