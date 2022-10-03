#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;ll a,b,c;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",(a+b+c)/2);
	}
	return 0;
}