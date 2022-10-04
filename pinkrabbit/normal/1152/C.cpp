#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
ll a,b;
ll ans,d,k;
void chk(ll x){
	ll i=(x-a%x)%x;
	ll lcm=(a+i)*(b+i)/x;
	if(lcm<ans||(lcm==ans&&i<k))ans=lcm,k=i;
}
int main(){
	scanf("%lld%lld",&a,&b);
	if(a==b)puts("0");
	else{
		if(a>b)std::swap(a,b);
		ans=a*b/__gcd(a,b),d=b-a,k=0;
		for(ll i=1;i*i<=d;++i){
			if(d%i)continue;
			chk(i);
			chk(d/i);
		}
		printf("%lld\n",k);
	}
	return 0;
}