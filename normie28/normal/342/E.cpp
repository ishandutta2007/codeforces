#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "robot.inp"
#define FILE_OUT "robot.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
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
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
typedef long long ll;
 
vector<int> g[100001];
int d[100001], q[100001], s, h, n, m, a, b;
 
void bfs()
{
	while (s != h)
	{
		int u = q[s++];
		for (int i = 0; i<g[u].size(); i++) 
			if (d[g[u][i]]>d[u] + 1) 
				d[g[u][i]] = d[u] + 1, q[h++] = g[u][i];
	}
	s = 0, h = 0;
}
 
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d%d", &a, &b);
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
		d[a] = 1 << 30, d[b] = 1 << 30;
	}
 
	q[h++] = 0;
	d[0] = 0;
	bfs();
 
	for (int i = 0; i < m; ++i)
	{
		int t, v;
		scanf("%d%d", &t, &v);
		if (t == 1)
		{
			d[v - 1] = 0;
			q[h++] = v - 1;
		}
		else
		{
			bfs();
			printf("%d\n", d[v - 1]);
		}
	}
 
	return 0;
}