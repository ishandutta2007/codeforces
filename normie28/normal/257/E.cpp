/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,decltype(cmp),rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;

#define maxn 100005
 
struct st
{
	int t,l,r,p;
	bool operator <(const st&B) const {return t<B.t;}
} a[maxn];
int N,M,K,s[maxn];
vector<st> u[maxn],v[maxn];
ll b[maxn],ans[maxn];
 
int sum(int x) {int d=0; for (int i=x; i; i-=i&-i) d+=s[i]; return d;}
void ins(int x,int d) {for (int i=x; i<=M; i+=i&-i) s[i]+=d;}
int find(int k)
{
	int p=0;
	for (int i=20; i>=0; i--) if (p+(1<<i)<=M&&s[p+(1<<i)]<k) k-=s[p+=1<<i];
	return p+1;
}
 
void init()
{
	scanf("%d%d",&N,&M);
	for (int i=1; i<=N; i++) scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r),b[i]=a[i].t,a[i].p=i;
	sort(a+1,a+N+1),sort(b+1,b+N+1),K=unique(b+1,b+N+1)-b-1;
}
 
void work(ll t,int p)
{
	for (auto i:u[p]) v[i.r].push_back(i),ins(i.r,1);
	for (auto i:v[p]) ans[i.p]=t;
	ins(p,-u[p].size()-v[p].size());
	u[p].clear(),v[p].clear();
}
 
void doit()
{
	b[++K]=1e18;
	ll t=0;
	for (int i=1,j=1,p=1; i<=K; i++)
	{
		for (;t<b[i];)
		{
			int n=sum(M),d=sum(p),u=n-sum(p-1),q;
			if (!n) {t=b[i]; continue;}
			if (u>=d)
			{
				q=find(n-u+1);
				if (t+q-p<=b[i]) t+=q-p,p=q,work(t,p);
				else p+=b[i]-t,t=b[i];
			}
			else
			{
				q=find(d);
				if (t+p-q<=b[i]) t+=p-q,p=q,work(t,p);
				else p-=b[i]-t,t=b[i];
			}
		}
		for (;j<=N&&a[j].t==b[i]; j++) ins(a[j].l,1),u[a[j].l].push_back(a[j]);
	}
	for (int i=1; i<=N; i++) printf("%I64d\n",ans[i]);
}
 
int main()
{
	init();
	doit();
}