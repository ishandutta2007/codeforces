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
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
vector<int>G[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	int lst=0,l=1,r=n,ans=0,aa=0,bb=0;
	F(i,1,n){
		if(l>r)break;
		++ans;
		int o=i&1;
		int now=0;
		if(o){
			while(l<=r&&now<=lst)now+=a[l++];
			aa+=now;
		}else{
			while(l<=r&&now<=lst)now+=a[r--];
			bb+=now;
		}
		lst=now;
	}
	printf("%d %d %d\n",ans,aa,bb);
}	return 0;
}