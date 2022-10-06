#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline LL Pow(LL B,LL E,LL M){LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f

map<int,int> mp;
set<int> st;

int n,m,k;
int d[4005];
int fa[4005]; int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}
char str[2005][2005];

int h[4005],nxt[4000005],to[4000005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int q[4005],l,r;
int lv[4005];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) {
		scanf("%s",str[i]+1);
		F(j,1,m)if(str[i][j]=='='){
			if(ff(i)!=ff(n+j))fa[ff(i)]=ff(n+j);
		}
	}
	F(i,1,n)F(j,1,m){
		int u=0,v=0;
		if(str[i][j]=='<') u=ff(i),v=ff(n+j);
		if(str[i][j]=='>') u=ff(n+j),v=ff(i);
		if(u&&v) ins(u,v), ++d[v];
	}
	l=1,r=0;
	F(i,1,n)if(ff(i)==i&&d[i]==0)q[++r]=i,lv[i]=1;
	F(j,1,m)if(ff(n+j)==n+j&&d[n+j]==0)q[++r]=n+j,lv[n+j]=1;
	while(l<=r){
		int u=q[l++];
		eF(i,u){
			--d[to[i]];
			lv[to[i]]=max(lv[to[i]],lv[u]+1);
			if(!d[to[i]])q[++r]=to[i];
		}
	}
	int ok=1;
	F(i,1,n)if(d[ff(i)]>0)ok=0;
	F(j,1,m)if(d[ff(n+j)]>0)ok=0;
	if(!ok)prts("No");
	puts("Yes");
	F(i,1,n)printf("%d ",lv[ff(i)]); puts("");
	F(j,1,m)printf("%d ",lv[ff(n+j)]); puts("");
	return 0;
}