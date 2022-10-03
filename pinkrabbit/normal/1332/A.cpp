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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
vector<int>G[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int a,b,c,d;
	int x,y,sx,sy,tx,ty;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%d%d%d%d%d%d",&x,&y,&sx,&sy,&tx,&ty);
	sx-=x,sy-=y,tx-=x,ty-=y;
	int ok=1;
	if(sx==0&&tx==0&&(a+b)>0)ok=0;
	if(sy==0&&ty==0&&(c+d)>0)ok=0;
	if(a>b&&-sx<a-b)ok=0;
	if(b>a&&tx<b-a)ok=0;
	if(c>d&&-sy<c-d)ok=0;
	if(d>c&&ty<d-c)ok=0;
	puts(ok?"Yes":"No");
}	return 0;
}