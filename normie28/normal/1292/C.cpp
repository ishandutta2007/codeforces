// Problem : C. Xenon's Attack on the Gangs
// Contest : Codeforces - Codeforces Round #614 (Div. 1)
// URL : https://codeforces.com/contest/1292/problem/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
ll n,m,k,par[3001],depth[3001],used[3001],t,t1,i,j;
vector<ll> gt[3001],subt[3001];
ll child[3001][3001], dp[3001][3001], lca[3001][3001];
void dfs (ll x, ll dep)
{
	used[x]=1;
	depth[x]=dep;
	for (ll g :gt[x]) if (!used[g])
	{
		dfs(g,dep+1);
		for (ll k : subt[g])
		{
			child[x][k]=g;
			subt[x].push_back(k);
		}
	}
	else
	{
		par[x]=g;
	}
	subt[x].push_back(x);
	for (ll g : gt[x]) for (ll gg : gt[x]) if ((g!=gg)and(g!=par[x])and(gg!=par[x]))
	{
		for (ll vx : subt[g]) for (ll vy: subt[gg])
		{
			lca[vx][vy]=x;
		}
	}
	for (ll g : subt[x]) 
	{
		lca[g][x]=x;
		lca[x][g]=x;
	}
	//cout<<"subt "<<x<<' '<<subt[x].size()<<endl;
}
ll calc (ll i, ll j)
{
	ll cand;
	if (dp[i][j]) return dp[i][j];
//	cout<<"calc "<<i<<' '<<j<<endl;
	if ((lca[i][j]==i)and(i!=j))
	{
		dp[i][j]=-1e18;
		return dp[i][j];
	}
	for (ll g : gt[i]) if (par[i]!=g)
	{
		if (lca[i][j]==j)
		cand=calc(g,j)+subt[g].size()*(n-subt[child[j][g]].size());
		else
		cand=calc(g,j)+subt[g].size()*subt[j].size();
		dp[i][j]=max(dp[i][j],cand);
	}
	if (lca[i][j]==j)
	{
		if (par[j])
		{
//		cout<<"trans "<<i<<' '<<par[j]<<' '<<subt[i].size()*(n-subt[par[j]].size()+1)<<endl;
			cand=calc(i,par[j])+subt[i].size()*(n-subt[child[par[j]][i]].size());
		dp[i][j]=max(dp[i][j],cand);
		}
		
	for (ll g : gt[j]) if ((par[j]!=g)and(child[j][i]!=g))
	{
//		cout<<"trans "<<i<<' '<<g<<' '<<subt[i].size()*subt[g].size()<<endl;
		cand=calc(i,g)+subt[i].size()*subt[g].size();
		dp[i][j]=max(dp[i][j],cand);
	}
	}
	else
	{
		
	for (ll g : gt[j]) if ((par[j]!=g))
	{
//		cout<<"trans "<<i<<' '<<g<<' '<<subt[i].size()*subt[g].size()<<endl;
		cand=calc(i,g)+subt[i].size()*subt[g].size();
		dp[i][j]=max(dp[i][j],cand);
	}
	}
	//cout<<"dp "<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	return dp[i][j];
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<n;i++)
    {
    	cin>>t>>t1;
    	gt[t].push_back(t1);
    	gt[t1].push_back(t);
    }
    
    dfs(1,0);
    
    for (i=1;i<=n;i++) calc(i,i);
    
    ll res=0;
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) {res=max(res,dp[i][j]); }
    cout<<res;
    
}
/*
 
ll n,m,k,par[3001],depth[3001],used[3001],t,t1,i,j;
vector<ll> gt[3001],subt[3001];
ll child[3001][3001], dp[3001][3001], lca[3001][3001];
void dfs (ll x, ll dep)
{
	used[x]=1;
	depth[x]=dep;
	for (ll g :gt[x]) if (!used[g])
	{
		dfs(g,dep+1);
		for (ll k : subt[g])
		{
			child[x][k]=g;
			subt[x].push_back(k);
		}
	}
	else
	{
		par[x]=g;
	}
	subt[x].push_back(x);
	for (ll g : gt[x]) for (ll gg : gt[x]) if ((g!=gg)and(g!=par[x])and(gg!=par[x]))
	{
		for (ll vx : subt[g]) for (ll vy: subt[gg])
		{
			lca[vx][vy]=x;
		}
	}
	for (ll g : subt[x]) 
	{
		lca[g][x]=x;
		lca[x][g]=x;
	}
}
ll calc (ll i, ll j)
{
	ll cand;
	if (dp[i][j]) return dp[i][j];
	for (ll g : gt[i]) if (par[i]!=g)
	{
		cand=calc(g,j)+subt[g].size()*(n-subt[j].size()+1);
		dp[i][j]=max(dp[i][j],cand);
	}
	if (lca[i][j]==j)
	{
		if (par[j])
		{
			cand=calc(i,par[j])+subt[i].size()*(n-subt[par[j]].size()+1);
		}
		
	for (ll g : gt[j]) if ((par[j]!=g)and(child[j][i]!=g))
	{
		cand=calc(i,g)+subt[i].size()*subt[g].size();
		dp[i][j]=max(dp[i][j],cand);
	}
	}
	else
	{
		
	for (ll g : gt[j]) if ((par[j]!=g))
	{
		cand=calc(i,g)+subt[i].size()*subt[g].size();
		dp[i][j]=max(dp[i][j],cand);
	}
	}
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<n;i++)
    {
    	cin>>t>>t1;
    	gt[t].push_back(t1);
    	gt[t1].push_back(t);
    }
    dfs(1,0);
    for (i=1;i<=n;i++) calc(i,i);
    ll res=0;
    for (i=1;i<=n;i++) for (j=1;j<=n;j++) res=max(res,dp[i][j]);
    cout<<res;
}
 
*/