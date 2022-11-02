#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200005];
int f[200005];
signed main(){
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		int maxx=0;
		for(int i=n;i>=1;i--){
			if(i+a[i]>n){
				f[i]=a[i];
			}
			else{
				f[i]=f[i+a[i]]+a[i];
			}
			maxx=max(maxx,f[i]);
		}
		for(int i=1;i<=n;i++)f[i]=0;
		printf("%lld\n",maxx);
	}
	return 0;
}