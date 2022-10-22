#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
#define ll long long 
int n,k;ll a[200005],b[200005],f[200005];
bool check(ll p){
	ll t,g;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		t=a[i];g=0;
		while(g<k-1){
			if(t>=b[i]){
				g+=t/b[i];t-=t/b[i]*b[i];continue; 
			}
			f[g]++;t+=p;
			if(f[g]>g+1)return 0;
		}
	}
	if(f[0]>1)return 0;
	for(int i=1;i<k;i++){
		f[i]+=f[i-1];if(f[i]>i+1)return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	ll ans=-1,l=0,r=10000000000000,mid;
	while(r>=l){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}