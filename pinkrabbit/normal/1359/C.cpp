#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int h,c,t;
	scanf("%d%d%d",&h,&c,&t);
	if(2*t<=h+c)puts("2");
	else{
		ll lb=1,rb=100000000,mid,ans=1;
		while(lb<=rb){
			mid=(lb+rb)/2;
			ll num=mid*h+(mid-1)*c;
			if(num>=(2*mid-1)*t)ans=mid,lb=mid+1;
			else rb=mid-1;
		}
		ll num1=ans*h+(ans-1)*c-(2*ans-1)*t;
		ll num2=(2*ans+1)*t-(ans+1)*h-ans*c;
		if(num1*(2*ans+1)<=num2*(2*ans-1))printf("%lld\n",2*ans-1);
		else printf("%lld\n",2*ans+1);
	}
}	return 0;
}