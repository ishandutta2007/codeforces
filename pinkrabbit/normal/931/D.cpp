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

int n,ans;
int cnt[100001]={1},dep[100001];

int h[100001],nxt[100001],to[100001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

void DFS(int u){
	eF(i,u){
		dep[to[i]]=dep[u]+1;
		++cnt[dep[u]+1];
		DFS(to[i]);
	}
}

int main(){
	scanf("%d",&n);
	int x;
	F(i,2,n) scanf("%d",&x), ins(x,i);
	DFS(1);
	F(i,0,n) ans+=(cnt[i]&1);
	printf("%d",ans);
	return 0;
}