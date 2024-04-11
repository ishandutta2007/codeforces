// Problem : B. Graph Subset Problem
// Contest : Codeforces - Codeforces Round #684 (Div. 1)
// URL : https://codeforces.com/contest/1439/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
 
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
 
//Constants.
#define MOD (ll(1000000007))
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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef int ll;
 
//---------END-------//
ll n,m,i,j,u,t,t1,k,v,arr[100001];
vector<ll> lis;
unordered_set<ll> gtc[100001];
vector<ll> gt[100001];
vector<ll> res;
ll used[100001];
void dfs(ll x)
{
	used[x]=1;
	res.push_back(x);
	for (ll g : gtc[x]) if (!used[g]) dfs(g);
}
struct cmp
{
    int operator()(int a, int b)
    {
        if (gtc[a].size()-gtc[b].size()) return (gtc[a].size()<gtc[b].size());
        return (a<b);
    }
};
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m>>k;
		for (i=1;i<=n;i++) gt[i].clear();
		res.clear();
		for (i=1;i<=m;i++)
		{
			cin>>u>>v;
			gt[u].push_back(v);
			gt[v].push_back(u);
		}
		for (i=1;i<=n;i++) gtc[i].clear();
		for (i=1;i<=n;i++) for (ll g : gt[i]) gtc[i].insert(g);
		deque<ll> br;
		ll killed=0;
		for (i=1;i<=n;i++) if (gtc[i].size()<k) br.push_back(i);
		while(br.size())
		{
			u=br.front();
			killed++;
			for (ll g : gtc[u])
			{
				gtc[g].erase(u);
				if (gtc[g].size()==k-1) br.push_back(g);
			}
			gtc[u].clear();
			br.pop_front();
		} 
		if (killed<n)
		{
			for (i=1;i<=n;i++) if (gtc[i].size())
			{
				for (j=1;j<=n;j++) used[j]=0;
				dfs(i);
				cout<<"1 "<<res.size()<<endl;
				for (ll g : res) cout<<g<<' ';
				break;
			}
		cout<<endl;
			continue;
		}
		if (k==1)
		{
			cout<<"2 \n 1";
		cout<<endl;
		}
		else
		{
			
		for (i=1;i<=n;i++) gtc[i].clear();
		for (i=1;i<=n;i++) for (ll g : gt[i]) gtc[i].insert(g);
		set<ll,cmp> br;
		ll killed=0;
		ll done=0;
		for (i=1;i<=n;i++) br.insert(i);
		while(br.size())
		{
			u=(*(br.begin()));
			killed++;
			if (gtc[u].size()==k-1)
			{
			    ll fail=0;
			    for (int g : gtc[u]) for (int h : gtc[u])
			    {
			        if (g<h)
			        {
			            if (gtc[g].find(h)==gtc[g].end()) {
			                fail=1; break;
			            }
			        }
			    }
			    if ((!fail)and(!done))
			    {
			        cout<<2<<endl;
			        cout<<u<<' ';
			        for (int g : gtc[u]) cout<<g<<' ';
			        done=1;
			    }
			}
			    for (int g : gt[u]) 
			    {
			        br.erase(g);
			        gtc[g].erase(u);
			        if (gtc[g].size()) br.insert(g);
			    }
			    br.erase(u);
			    gtc[u].clear();
		} 
		if (!done) cout<<-1;
		cout<<endl;
		}
	}
}