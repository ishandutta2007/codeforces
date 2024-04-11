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
ll n;
int main(){
	scanf("%lld",&n);
	int x=pow(n,1/10.);
	while((ll)x*x*x*x*x*x*x*x*x*x<=n)++x;
	while((ll)x*x*x*x*x*x*x*x*x*x>n)--x;
	ll y=(ll)x*x*x*x*x*x*x*x*x*x;
	int k=0;
	while(y<n)++k,y/=x,y*=x+1;
	char s[]="codeforces";
	F2(i,0,10){
		F(j,1,x+(i<k))putchar(s[i]);
	}
	return 0;
}