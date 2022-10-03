#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define MM 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,k;
int h[MN],nxt[MM],to[MM],w[MM],tot;
inline void ins(int x,int y,int z){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}
ll f[MN],g[MN];
void dfs(int u,int fz){
	static ll s1[MN],s2[MN];
	static int p[MN];
	for(int i=h[u];i;i=nxt[i])if(to[i]!=fz)dfs(to[i],u);
	int c=0;
	for(int i=h[u];i;i=nxt[i])if(to[i]!=fz)++c,s1[c]=max(f[to[i]],g[to[i]]+w[i]),s2[c]=f[to[i]],p[c]=c;
	sort(p+1,p+c+1,[](int i,int j){return s1[i]-s2[i]>s1[j]-s2[j];});
//	printf("u=%d\n",u);
//	F(i,1,c)printf("(%lld,%lld)\n",s1[p[i]],s2[p[i]]);
	s1[0]=s1[c+1]=s2[0]=s2[c+1]=0,p[0]=0,p[c+1]=c+1;
	F(i,1,c)s1[p[i]]+=s1[p[i-1]];
	dF(i,c,1)s2[p[i]]+=s2[p[i+1]];
	int t1=min(c,k),t2=min(c,k-1);
	f[u]=s1[p[t1]]+s2[p[t1+1]];
	g[u]=s1[p[t2]]+s2[p[t2+1]];
//	debug("(f,g)[%d] = (%lld,%lld)\n",u,f[u],g[u]);
}//f>=g
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int x,y,z;
		scanf("%d%d",&n,&k),tot=0;
		F(i,1,n)h[i]=0;
		F(i,2,n)scanf("%d%d%d",&x,&y,&z),ins(x,y,z),ins(y,x,z);
		dfs(1,0);
		printf("%lld\n",f[1]);
	}
	return 0;
}