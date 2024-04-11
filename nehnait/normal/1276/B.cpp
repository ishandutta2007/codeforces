#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
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
int n,m,A,B;
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int del[MN],vis[MN],col[MN];
void DFS(int u,int c){
	vis[u]=1,col[u]|=c;
	for(int i=h[u];i;i=nxt[i])if(!del[to[i]]&&!vis[to[i]])DFS(to[i],c);
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){int x,y;
	scanf("%d%d%d%d",&n,&m,&A,&B),tot=0;
	F(i,1,n)h[i]=0,col[i]=0;
	F(i,1,m)scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
	F(i,1,n)vis[i]=0;
	del[A]=1,DFS(B,1),del[A]=0;
	F(i,1,n)vis[i]=0;
	del[B]=1,DFS(A,2),del[B]=0;
//	F(i,1,n)printf("%d,",col[i]);puts("");
	int C=-1,D=-1;
	F(i,1,n)if(col[i]==1)++C;else if(col[i]==2)++D;else{}
	printf("%lld\n",(ll)C*D);
}	return 0;
}