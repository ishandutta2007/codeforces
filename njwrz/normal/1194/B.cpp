#include<bits/stdc++.h>
using namespace std;
int a[400001],x[50001],y[50001];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int k,l;
	cin>>k;
	for(l=0; l<k; l++) {
		int n,m;
		cin>>n>>m;
		char z;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>z;
				if(z!='.') {
					a[i*m+j]=0;
				} else a[i*m+j]=1;
			}
		}
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				x[i]+=a[i*m+j];
				y[j]+=a[i*m+j];
			}
		}
		int ans=100000000;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				ans=min(ans,x[i]+y[j]-a[i*m+j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}