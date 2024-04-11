#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,k;
int h[1000001],nxt[2000001],to[2000001],tot;
void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int que[1000001],l,r;
bool v[1000001];
int dep[1000001];
int fa[1000001][20];

int main(){
	int x,y;
	scanf("%d%d",&n,&k);
	F(i,1,n-1) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	que[l=r=1]=n; dep[n]=1;
	while(l<=r){
		int u=que[l++]; v[u]=1;
		for(int i=h[u];i;i=nxt[i])
			if(!v[to[i]]) que[++r]=to[i], dep[to[i]]=dep[u]+1, fa[to[i]][0]=u;
	}
	F(j,1,19) F(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	F(i,1,n) v[i]=0;
	int cnt=1; v[n]=1; v[0]=1;
	dF(i,n-1,1){
		if(v[i]) continue;
		int cur=i;
		dF(j,19,0) if(!v[fa[cur][j]]) cur=fa[cur][j];
		if(cnt+(dep[i]-dep[cur]+1)<=n-k){
			for(int j=i;dep[j]>=dep[cur];j=fa[j][0]) v[j]=1;
			cnt+=(dep[i]-dep[cur]+1);
		}
	}
	F(i,1,n) if(!v[i]) printf("%d ",i);
	return 0;
}