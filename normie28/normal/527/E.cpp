
// Problem : E. Data Center Drama
// Contest : Codeforces - Codeforces Round #296 (Div. 2)
// URL : https://codeforces.com/problemset/problem/527/E
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
#define pb push_back
typedef long long ll;
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j;
const int maxn = 100 * 1000 + 5;
const int maxm = 500 * 10 * 100 + 5;
vector <int> adj[maxn] , ind[maxn] , ans;
bool mark[maxm];
int pt[maxn];
void tour(int v) 
{
	while(pt[v] < (int)adj[v].size())
	{
		int u = adj[v][pt[v]], e = ind[v][pt[v]];
		pt[v] ++;
		if(! mark[e])
		{
			mark[e] = true;
			tour(u);	
		}
	} 
	ans.push_back(v + 1);
	return;
}
int main()
{
	cin >> n >> m;
	int a , b;
	for(int i = 0 ; i < m ; i ++)
	{
		cin >> a >> b;
		a --; b --;
		adj[a].pb(b);
		adj[b].pb(a);
		ind[a].pb(i); 
		ind[b].pb(i);
	}
	bool flag = false;
	int indd;
	for(int i = 0 ; i < n ; i ++)
	{
		if(adj[i].size() % 2 == 1)
		{
			if(!flag)
			{
				flag = true;
				indd = i;
			}
			else
			{
				flag = false;
				adj[i].pb(indd);
				adj[indd].pb(i);
				ind[i].push_back(m); 
				ind[indd].push_back(m);
				m ++;
			}
		}
	}
	flag = false;
	if(m % 2 == 1)
	{
		m ++;
		flag = true;
	}
	cout << m << endl;
	tour(0);
	if(flag)
		cout << ans[0] << ' ' << ans[0] << endl;
	for(int i = 0 ; i < ans.size() - 1 ; i ++)
	{
		if(i % 2 == 1)
		{
			cout << ans[i] << ' ' << ans[i + 1] << endl;
		}
		else
			cout << ans[i + 1] << ' ' << ans[i] << endl;
	}
}