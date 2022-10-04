#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){if(!(base%=_mod))return 0;int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){if(!(base%=_mod))return 0;ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,m;
int a[200001],b[200001],p[200001];

int h[200001],nxt[400001],to[400001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

bool cmp(int i,int j){return a[i]<a[j];}

int main(){ int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",a+i), p[i]=i;
	sort(p+1,p+n+1,cmp);
	int sum=0,cnt=0;
	F(i,1,n){
		if(a[p[i]]!=a[p[i-1]]) sum+=cnt, cnt=0;
		b[p[i]]=sum;
		++cnt;
	}
	F(i,1,m) scanf("%d%d",&x,&y), a[x]!=a[y]?b[a[x]>a[y]?x:y]--:0;
	F(i,1,n) printf("%d ",b[i]);
	return 0;
}