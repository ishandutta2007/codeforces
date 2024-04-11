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

int n,q,m,k;
int l[300005],r[300005];
int fa[300005]; int ff(int x){return fa[x]?fa[x]=ff(fa[x]):x;}
int M[3005][3005];
char str[300005];

int h[300005],nxt[600005],to[600005],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int main(){
	scanf("%d",&n);
	F(i,1,n)l[i]=r[i]=i;
	F(i,2,n){
		int x,y;
		scanf("%d%d",&x,&y);
		x=ff(x),y=ff(y);
		ins(r[x],l[y]);
		fa[x]=y; l[y]=l[x];
	}
	int k=l[ff(1)],f=0;
	printf("%d ",k);
	F(i,2,n){
		eF(j,k)if(to[j]!=f){
			printf("%d ",to[j]);
			f=k,k=to[j];
			break;
		}
	}
	return 0;
}