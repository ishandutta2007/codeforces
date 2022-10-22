#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int k;
		LL x;
		scanf("%d%lld",&k,&x);
		int l=1,r=k*2-1,ans=k*2-1;
		auto sum=[&](LL l,LL r){
			return (l+r)*(r-l+1)/2;
		};
		auto calc=[&](LL x){
			return x<=k?sum(1,x):sum(1,k-1)+sum(k*2-x,k);
		};
		while(l<=r){
			int mid=l+((r-l+1)>>1);
			if(calc(mid)>=x){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}