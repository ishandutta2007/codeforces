#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
ll n,k,s,t;
int main(){
	scanf("%lld",&t);
	while(t--){
		s=0;
		scanf("%lld%lld",&n,&k);
		while(n)s+=n%k+1,n/=k;
		printf("%lld\n",s-1);
	}
	return 0;
}