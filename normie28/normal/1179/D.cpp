/*
        Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
struct node
{
	node *nl=0, *nr=0;
	ll dom=0;
	~node()
	{
		delete this->nl;
		delete this->nr;
	}
};
struct dynamic_li_chao
{
	vector<pii(ll)> func={{0,3e18+7}};
	ll calc (ll cur, ll x)
	{
		return (func[cur].fi)*x+(func[cur].se);
	}
	node start;
	void add_line(ll a, ll b, ll l, ll r)
	{
		func.emplace_back(a,b);
		update(-1e9,1e9+1,&start,func.size()-1,l,r);
	}
	void update(ll l, ll r, node* cur, ll diff , ll tl, ll tr)
	{
		if ((l>=tl)and(r-1<=tr))
		{
		if (cur->dom==0)
		{
			cur->dom=diff;
		}
		else if (l+1==r) 
		{
			if (calc(cur->dom,l)>calc(diff,l))
			cur->dom=diff;
		}
		else
		{
			ll mid=(l+r)/2;
			ll doml=(calc(cur->dom,l)>calc(diff,l));
			ll domm=(calc(cur->dom,mid)>calc(diff,mid));
			if (domm)
			{
				ll z=cur->dom;
				cur->dom=diff;
				diff=z;
			}
			if (doml==domm)
			{
				if (!cur->nr) cur->nr=new(node);
				update(mid,r,cur->nr,diff,tl,tr);
			}
			else
			{
				if (!cur->nl) cur->nl=new(node);
				update(l,mid,cur->nl,diff,tl,tr);
			}
		}
		}
		else if ((l>tr)or(r-1<tl)) return;
		else
		{
			ll mid=(l+r)/2;
			if (!cur->nr) cur->nr=new(node);
			update(mid,r,cur->nr,diff,tl,tr);
			if (!cur->nl) cur->nl=new(node);
			update(l,mid,cur->nl,diff,tl,tr);
		}
	}
	ll get(ll x)
	{
		return getK(-1e9,1e9+1,&start,x);
	}
	ll getK(ll l, ll r, node* cur, ll tar)
	{
		ll res1=calc(cur->dom,tar);
		if (l+1==r) return res1;
		ll res2=3e18+7;
		ll mid=(l+r)/2;
		if ((tar<mid)and(cur->nl)) res2=getK(l,mid,cur->nl,tar); 
		else if ((tar>=mid)and(cur->nr)) res2=getK(mid,r,cur->nr,tar);
		return min(res1,res2);
	}
};
vector<ll> gt[500001],gtd[500001];
ll sz[500001],dp[500001];
ll n,m,i,j,k,t,t1,u,v,a,b,res=1e18;
void dfs(ll x)
{
	sz[x]=1;
	for (ll g : gt[x]) if (!sz[g])
	{
		gtd[x].push_back(g);
		dfs(g);
		sz[x]+=sz[g];	
	} 
}
void calc(ll x)
{
	if (gtd[x].size()==0)
	{
		dp[x]=0;
		res=min(res,n*(n-1)/2);
	}
	else
	{
//		cout<<"check: "<<x<<endl;
		dp[x]=1e18;
		for (ll g : gtd[x])
		{
			calc(g);
//		cout<<"to: "<<g<<endl;
			dp[x]=min(dp[x],dp[g]+(sz[x]-sz[g]-1)*(sz[x]-sz[g])/2);
			res=min(res,dp[g]+(sz[1]-sz[g]-1)*(sz[1]-sz[g])/2);
		}
			auto dl=new (dynamic_li_chao);
		for (i=1;i<gtd[x].size();i++)
		{
			dl->add_line(
			-(2*sz[gtd[x][i-1]]+1),
			sz[gtd[x][i-1]]+2*dp[gtd[x][i-1]]+sz[gtd[x][i-1]]*sz[gtd[x][i-1]],
			0,
			n
			);
			u=dl->get(n-sz[gtd[x][i]]);
			u+=(n-sz[gtd[x][i]])*(n-sz[gtd[x][i]]);
			u/=2;
			u+=dp[gtd[x][i]];
			res=min(res,u);
		}
		delete dl;
			auto dr=new(dynamic_li_chao);
		for (i=gtd[x].size()-2;i>=0;i--)
		{
			dr->add_line(
			-(2*sz[gtd[x][i+1]]+1),
			sz[gtd[x][i+1]]+2*dp[gtd[x][i+1]]+sz[gtd[x][i+1]]*sz[gtd[x][i+1]],
			0,
			n
			);
			u=dr->get(n-sz[gtd[x][i]]);
			u+=(n-sz[gtd[x][i]])*(n-sz[gtd[x][i]]);
			u/=2;
			u+=dp[gtd[x][i]];
			res=min(res,u);
		}
		delete dr;
	}
}
int eu[500010],ev[500001];
int main()
{
	fio;
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		eu[i]=u;
		ev[i]=v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs(1);
	calc(1);
	for (i=1;i<=n;i++)
	{
	//	cout<<"i= "<<i<<' ';
	//	cout<<"sz= "<<sz[i]<<' ';
	//	cout<<endl;
	}
	u=n*(n-1)-res;cout<<u;
	
}