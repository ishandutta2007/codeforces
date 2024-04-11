#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int T,n,a[N],b[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d%d",&a[i],&b[i]),swap(a[i],b[i]);
		int l=1,r=n,ans=0;
		auto chk=[&](int mid){
			int tt=0;
			rep(i,1,n)if(tt<=a[i]&&tt+1+b[i]>=mid)tt+=1;
			return tt>=mid;
		};
		while(l<=r){
			int mid=(l+r)>>1;
			if(chk(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}