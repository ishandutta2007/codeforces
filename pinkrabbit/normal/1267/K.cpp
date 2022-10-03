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
ll c[25][25];
int b[30],a[30],t;
int main(){int tests=1;scanf("%d",&tests);
F(i,0,20)F(j,0,20)c[i][j]=j?c[i-1][j-1]+c[i-1][j]:1;
while(tests--){
	scanf("%lld",&n),t=0;
	F(i,2,30)if(n)b[++t]=n%i,n/=i;else break;
	sort(b+1,b+t+1);
//	F(i,1,t)printf("%d,",b[i]);puts("");
	F(i,0,t)a[i]=0;
	F(i,1,t)++a[b[i]];
//	F(i,0,t)printf("%d,",a[i]);puts("");
	int p=t;ll ans=1,ansr=1;
	dF(i,t,1)ans*=c[p-i+1][a[i]],p-=a[i];
	if(a[0]){
		p=t-1;
		dF(i,t,1)ansr*=c[p-i+1][a[i]],p-=a[i];
	}else ansr=0;
	printf("%lld\n",ans-ansr-1);
}	return 0;
}