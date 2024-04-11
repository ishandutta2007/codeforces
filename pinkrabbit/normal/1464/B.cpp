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
char s[MN];
int n,x,y;
int f0[MN],f1[MN],g0[MN],g1[MN];
ll f[MN],g[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%s%d%d",s+1,&x,&y),n=strlen(s+1);
	if(x>y)reverse(s+1,s+n+1),swap(x,y);
	f[0]=f0[0]=f1[0]=0;
	F(i,1,n){
		f0[i]=f0[i-1]+(s[i]!='1');
		f1[i]=f1[i-1]+(s[i]=='1');
		f[i]=f[i-1]+(s[i]=='1'?(ll)x*f0[i-1]:(ll)y*f1[i-1]);
	}
	g[n+1]=g0[n+1]=g1[n+1]=0;
	dF(i,n,1){
		g0[i]=g0[i+1]+(s[i]=='0');
		g1[i]=g1[i+1]+(s[i]!='0');
		g[i]=g[i+1]+(s[i]=='0'?(ll)x*g1[i+1]:(ll)y*g0[i+1]);
	}
	ll ans=infll;
	F(i,0,n)ans=min(ans,f[i]+g[i+1]+(ll)x*f0[i]*g1[i+1]+(ll)y*f1[i]*g0[i+1]);
	printf("%lld\n",ans);
}	return 0;
}