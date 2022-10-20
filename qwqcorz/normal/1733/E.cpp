#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=125;
const int n=120;

ll f[N][N];
void work() {
	ll T,x,y;
	cin>>T>>x>>y;
	T-=x+y;
	if (T<0) {
		cout<<"NO\n";
		return;
	}
	memset(f,0,sizeof(f));
	f[0][0]=T;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			f[i][j+1]+=f[i][j]-f[i][j]/2;
			f[i+1][j]+=f[i][j]/2;
		}
	}
	int i=0,j=0;
	while (i<n&&j<n) {
		if (i==x&&y==j) {
			cout<<"YES\n";
			return;
		}
		if (f[i][j]&1) {
			i++;
		} else {
			j++;
		}
	}
	cout<<"NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}