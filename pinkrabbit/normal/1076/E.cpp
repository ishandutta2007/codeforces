#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
#define SZ(x) ((int)(x).size())
#define prts(x) return puts(x),0
#define pirtf(x) return printf("%d\n",x),0
#define re return
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline LL Gcd(LL X,LL Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int B,LL E,int M){if(!(B%=M))return 0;int A=1;for(;E;E>>=1,B=(LL)B*B%M)E&1?A=(LL)A*B%M:0;return A;}
inline LL Pow(LL B,LL E,LL M){if(!(B%=M))return 0;LL A=1;for(;E;E>>=1,B=B*B%M)E&1?A=A*B%M:0;return A;}
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,m;
int a[300005],b[300005];
int f[300005],g[300005];
int M[3005][3005];
char str[300005];

int h[300005],q[300005],nxt[900005],to[900005],w[900005],tot;
inline void ins(int *h,int x,int y,int z=0){nxt[++tot]=h[x];to[tot]=y;w[tot]=z;h[x]=tot;}

int de[300005],faz[300005];

void DFS0(int u,int f){
	faz[u]=f, de[u]=de[f]+1;
	eF(h,i,u) if(to[i]!=f) DFS0(to[i],u);
}

LL bit[300005], Sum;
inline LL Qur(int i){LL a=0;for(;i;i-=i&-i)a+=bit[i];return a;}
inline void Add(int i,int x){for(;i<=300000;i+=i&-i)bit[i]+=x;}

LL Ans[300005];
void DFS(int u){
	eF(q,i,u){
		int dep=to[i], xx=w[i];
		Sum+=xx, Add(dep,xx);
	}
	Ans[u]=Sum-Qur(de[u]-1);
	eF(h,i,u) if(to[i]!=faz[u]) DFS(to[i]);
	eF(q,i,u){
		int dep=to[i], xx=w[i];
		Sum-=xx, Add(dep,-xx);
	}
}

int main(){
	int x,y,z;
	scanf("%d",&n);
	F(i,2,n) scanf("%d%d",&x,&y), ins(h,x,y), ins(h,y,x);
	DFS0(1,0);
	scanf("%d",&m);
	F(i,1,m) scanf("%d%d%d",&x,&y,&z), ins(q,x,min(300000,de[x]+y),z);
	DFS(1);
	F(i,1,n) printf("%lld ",Ans[i]);
	return 0;
}