#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
ll n; int q;
int main(){
	scanf("%lld%d",&n,&q);
	F(i,1,q){
		ll x, ans=0, len=n;
		int k=0;
		scanf("%lld",&x);
		while(x%2==k){
			ans+=k==0?(len+1)/2:len/2;
			x=(x+k)/2;
			int len2=len;
			len=k==0?len/2:(len+1)/2;
			k^=(len2&1);
		}
		printf("%lld\n",ans+(x+(k^1))/2);
	}
	return 0;
}