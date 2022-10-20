#include<bits/stdc++.h>
#define ll long long
using namespace std;

void work() {
	int n,x[3],y[3],a[2]={};
	cin>>n;
	for (int i=0;i<3;i++) {
		cin>>x[i]>>y[i];
		a[(x[i]+y[i])&1]++;
	}
	int x0,y0;
	cin>>x0>>y0;
	for (int i=0;i<3;i++) {
		if (x[i]==1||x[i]==n) {
			if (y[i]==1||y[i]==n) {
				bool ok=1;
				for (int j=0;j<3;j++) {
					ok&=abs(x[i]-x[j])+abs(y[i]-y[j])<=1;
				}
				if (ok) {
					if (x0==x[i]||y0==y[i]) {
						cout<<"YES\n";
					} else {
						cout<<"NO\n";
					}
					return;
				}
			}
		}
	}
	if (a[(x0+y0)&1]==2) {
		cout<<"YES\n";
	} else {
		int t=0;
		for (int i=0;i<3;i++) {
			if (a[(x[i]+y[i])&1]==1) {
				t=x[i]&1;
			}
		}
		if (t==(x0&1)) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	} 
	
	return 0;
}