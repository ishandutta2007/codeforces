#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1048583
#define MM 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,v;
int a[MN],b[MN],d[MN],vis[MN];
int h[MN],nxt[MM],to[MM],ve[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;ve[tot]=0;h[x]=tot;}
void dfs(int u){
	vis[u]=1;
	for(int i=h[u];i;i=nxt[i])if(!vis[to[i]])dfs(to[i]);
}
int stk[MN],tp;
void eul(int u){
	for(int &i=h[u];i;i=nxt[i]){
		if(ve[i])continue;
		ve[i]=ve[i^1]=1;
		int e=i^1;
		eul(to[i]);
		stk[++tp]=e;
	}
}
int main(){
	v=1<<20,tot=1;
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",a+i,b+i);
	int ans=-1;
	F(j,0,20){
//		printf("j=%d\n",j);
		int x=(1<<j)-1;
		F(i,1,n)ins(a[i]&x,b[i]&x),ins(b[i]&x,a[i]&x),++d[a[i]&x],++d[b[i]&x]/*,printf("%d--%d\n",a[i]&x,b[i]&x)*/;
		int gg=0;
		F2(i,0,v)if(d[i]&1)gg=1;
		if(!gg){
			F2(i,0,v)if(d[i]&&!vis[i]){dfs(i);break;}
			F2(i,0,v)if(d[i]&&!vis[i])gg=1;
		}
		if(gg){
			ans=j-1;
			break;
		}
		tp=0;
		F2(i,0,v)if(d[i]){eul(i);break;}
//		F(i,1,tp)printf("%d,",stk[i]);puts("");
		F2(i,0,v)vis[i]=h[i]=d[i]=0;
		tot=1;
	}
	if(ans==-1)ans=20;
	printf("%d\n",ans);
	F(i,1,n)printf("%d %d ",stk[i]-1,(stk[i]^1)-1);
	return 0;
}