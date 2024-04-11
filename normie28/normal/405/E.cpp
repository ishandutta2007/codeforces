
// Problem : E. Graph Cutting
// Contest : Codeforces - Codeforces Round #238 (Div. 2)
// URL : https://codeforces.com/problemset/problem/405/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
int n,m,k,c[501],pos[100001],t,t1,i,j,used[100001];
pii edges[100001];
vector<int> gt[100001];
int oth (int a, pii b)
{
	if (a!=b.fi) return b.fi; else return b.se;
}
vector<int> dfs(int x)
{
//	cout<<"dfs"<<' '<<x<<endl;
	vector<int> n_used;
	for (int g:gt[x])
	{
		if (!used[g])
		{
			n_used.push_back(g);
			used[g]=1;
		}
	}
	
	vector<int> pable;
	
	for (int g: n_used)
	{
		vector<int> res=dfs(oth(x,edges[g]));
		if (res.size())
		cout<<x<<' '<<oth(x,edges[g])<<' '<<res[0]<<endl;
		else pable.push_back(g);
	}
	
	for (int i=0;i<int(pable.size())-1;i+=2)
	{
		cout<<oth(x,edges[pable[i]])<<' '<<x<<' '<<oth(x,edges[pable[i+1]])<<endl;
	}
	
	if (pable.size()%2)
	return {oth(x,edges[pable[pable.size()-1]])};
	else return {};
	
}
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    if (m%2) cout<<"No solution";
    else
    {
   // 	cout<<n<<' '<<m<<endl;
    	for (i=0;i<m;i++)
    	{
    		int a,b; cin>>a>>b;
    		edges[i]={a,b};
    		gt[a].push_back(i);
    		gt[b].push_back(i);
    	}
   	dfs(1);
    }
}