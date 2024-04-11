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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//

const ll oo=1<<20;
ll minv[1<<20],limit;
void insert(ll p,ll v,ll o=1,ll l=1,ll r=limit)
{
	if(l==r){minv[o]=min(minv[o],v);return;}
	ll m=(l+r)>>1;
	if(p<=m)insert(p,v,o*2,l,m);
	else insert(p,v,o*2+1,m+1,r);
	minv[o]=min(minv[o*2],minv[o*2+1]);
}
ll query(ll x,ll y,ll o=1,ll l=1,ll r=limit)
{
	if(x>y||minv[o]>=oo)return oo;
	if(x<=l&&r<=y)return minv[o];
	ll m=(l+r)>>1,res=oo;
	if(x<=m)res=min(res,query(x,y,o*2,l,m));
	if(m<y)res=min(res,query(x,y,o*2+1,m+1,r));
	return res;
}
ll d[1<<17],t[1<<17],n,g,r,q;
inline ll dist(ll i,ll j){return d[j-1]-(i?d[i-1]:0);}
inline ll adj(ll x){return (x%(g+r)+g+r)%(g+r);}
vector<int> v{-oo};
inline ll compute(ll x)
{
	if(adj(g+x)<g)return query(lower_bound(v.begin(),v.end(),adj(g+x))-v.begin(),upper_bound(v.begin(),v.end(),adj(g+r+x-1))-v.begin()-1);
	if(adj(g+x)==g)return query(lower_bound(v.begin(),v.end(),g)-v.begin(),v.size()-1);
	return min(query(lower_bound(v.begin(),v.end(),adj(g+x))-v.begin(),v.size()-1),query(1,upper_bound(v.begin(),v.end(),adj(g+r+x-1))-v.begin()-1));
}
int main()
{
	scanf("%lld%lld%lld",&n,&g,&r);
	for(ll i=0;i<=n;i++)scanf("%lld",d+i);
	for(ll i=1;i<=n;i++)d[i]+=d[i-1];
	memset(minv,0x3f,sizeof minv);
	for(ll i=0;i<=n;i++)v.push_back(d[i]%(g+r));
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	limit=v.size()+2;
	t[n]=d[n]-d[n-1];
	insert(lower_bound(v.begin(),v.end(),d[n-1]%(g+r))-v.begin(),n);
	for(ll i=n-1;i;i--)
	{
		ll j=compute(d[i-1]);
		if(j>n)t[i]=dist(i,n+1);
		else t[i]=t[j]+dist(i,j)+g+r-dist(i,j)%(g+r);
		insert(lower_bound(v.begin(),v.end(),d[i-1]%(g+r))-v.begin(),i);
	}
	scanf("%lld",&q);
	while(q--)
	{
		ll x;
		scanf("%lld",&x);
		ll j=compute(-x);
		printf("%lld\n",j>n?dist(0,n+1)+x:t[j]+dist(0,j)+g+r-(dist(0,j)+x)%(g+r)+x);
	}
	return 0;
}