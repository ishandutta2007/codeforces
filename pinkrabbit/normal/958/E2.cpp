#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<ll,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
const int INF=0x3f3f3f3f;

int n,k; ll ans;
ll a[500009]; int l[500009],r[500009];
int vis[500009];
priority_queue<pii,vector<pii>,greater<pii> > pq;

int main(){
	scanf("%d%d",&k,&n);
	F(i,1,n) scanf("%d",a+i);
	sort(a+1,a+n+1); --n;
	F(i,1,n) a[i]=a[i+1]-a[i];
	F(i,1,n) pq.push(make_pair(a[i],i)), l[i]=i-1, r[i]=i+1;
	r[0]=1; l[n+1]=n; a[0]=a[n+1]=0x3f3f3f3f3f3f3f3f;
	F(i,1,k){
		while(vis[pq.top().second]) pq.pop();
		pii p=pq.top(); pq.pop();
		ans+=p.first; int x=p.second;
		a[x]=a[l[x]]+a[r[x]]-a[x];
		p.first=a[x];
		vis[l[x]]=vis[r[x]]=1;
		l[x]=l[l[x]];r[l[x]]=x;
		r[x]=r[r[x]];l[r[x]]=x;
		pq.push(p);
	} printf("%lld",ans);
	return 0;
}