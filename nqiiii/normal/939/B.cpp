#include<cstdio>
typedef long long ll;
ll n,ans=-1,cnt;
int k,id;
int main(){
	scanf("%lld%d",&n,&k);
	for(int i=1;i<=k;++i){
		ll x; scanf("%lld",&x);
		if(n/x*x>ans){
			ans=n/x*x; id=i; cnt=n/x;
		}
	}
	printf("%d %lld",id,cnt);
}