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
int deg[100001],v[100001];
int que[100001],l=1,r;
bool inq[100001];
int Ax[100001],Ay[100001],m;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d",deg+i,v+i);
	F(i,1,n) if(deg[i]==1) que[++r]=i, inq[i]=1;
	while(l<=r){
		int u=que[l++];
		if(deg[u]!=1) continue;
		Ax[++m]=u, Ay[m]=v[u]+1;
		v[v[u]+1]^=(u-1); --deg[v[u]+1];
		if(deg[v[u]+1]==1&&!inq[v[u]+1]) que[++r]=v[u]+1;
	}
	printf("%d\n",m);
	F(i,1,m) printf("%d %d\n",Ax[i]-1,Ay[i]-1);
	return 0;
}