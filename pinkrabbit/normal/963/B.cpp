#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n;
int h[200001],nxt[400001],to[400001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

bool pri[200001];
void print(int u,int f){
	printf("%d\n",u); pri[u]=1;
	eF(i,u) if(to[i]!=f&&!pri[to[i]]) print(to[i],u);
}

int s[200001];
int DFS(int u,int f){
	s[u]=(f!=0);
	eF(i,u) if(to[i]!=f) s[u]^=DFS(to[i],u);
	if(s[u]==0) {print(u,f); return 0;}
	else return 1;
}

int main(){
	scanf("%d",&n);
	if(n%2==0) {puts("NO"); return 0;}
	else puts("YES");
	F(i,1,n){ int x;
		scanf("%d",&x);
		if(x) ins(i,x), ins(x,i);
	}
	DFS(1,0);
	return 0;
}