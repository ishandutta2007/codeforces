
// Problem : E. Magical Permutation
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1163/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
const int N = 3501;
const double eps = 1e-8;
 
double a[N][N], ans[N];
int n, m, t, id[N << 1];
 
void pivot(int l, int e) {
	swap(id[e], id[n + l]);
	double r = a[l][e]; a[l][e] = 1;
	for (int j = 0; j <= n; ++j)
		a[l][j] /= r;
	for (int i = 0; i <= m; ++i)
		if (i != l) {
			r = a[i][e]; a[i][e] = 0;
			for (int j = 0; j <= n; ++j)
				a[i][j] -= r * a[l][j];
		}
}
bool solve()
{
	int i, j, l, e;
	double k, kk;
	for (j = 1; j <= n; ++j) 
		id[j] = j;
	while (true) {
		l = e = 0; k = -eps;
		for (i = 1; i <= m; ++i)
			if (a[i][0] < k && (!l || (rand() & 1))) {
				k = a[i][0];
				l = i;
			}
		if (!l) break;
		k = -eps;
		for (j = 1; j <= n; ++j)
			if (a[l][j] < k && (!e || (rand() & 1))) {
				k = a[l][j];
				e = j;
			}
		if (!e) 
		{ 
			//puts("Infeasible"); 
			return false; 
		}
		pivot(l, e);
	}
 
	while (true) {
		for (j = 1; j <= n; ++j)
			if (a[0][j] > eps)
				break;
		if ((e = j) > n) break;
		k = 1e18; l = 0;
		for (i = 1; i <= m; ++i)
			if (a[i][e] > eps && (kk = (a[i][0] / a[i][e])) < k) {
				k = kk;
				l = i;
			}
		if (!l) { 
			puts("Unbounded"); 
		    return  false;
		}
		pivot(l, e);
	}
	for (i = 1; i <= m; ++i)
		ans[id[n + i]] = a[i][0];
	return true;
}
vector<int> edge[600], edge2[600];
int fa1[600], fa2[600];
void dfs1(int cur, int fa)
{
	for (auto &p : edge[cur])
		if (p != fa)
		{
			fa1[p] = cur;
			dfs1(p, cur);
		}
}
void dfs2(int cur, int fa)
{
	for (auto &p : edge2[cur])
		if (p != fa)
		{
			fa2[p] = cur;
			dfs2(p, cur);
		}
}
void add1(int i, int cur, int fa)
{
	//cout << "edge: "<<cur << " " << fa << endl;
    a[i * 2][cur] = -1.0;
	a[i * 2 + 1][cur] = 1.0;
	for (auto &p : edge[cur])
		if (p != fa)
		{
			add1(i, p, cur);
		}
}
void add2(int i, int cur, int fa)
{
	a[i * 2][cur] = -1.0;
	a[i * 2 + 1][cur] = 1.0;
	for (auto &p : edge2[cur])
		if (p != fa)
		{
			add2(i, p, cur);
		}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long fa, fb;
	long long fw;
	int  u, v, aa, bb, k, x, r1, r2;
	cin >> n >> r1 >> r2;
	for (int i = 1; i <= n; ++i)
	{
		cin >> fw;
		a[0][i] = fw;
	}
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		edge2[u].push_back(v);
		edge2[v].push_back(u);
	}
	dfs1(r1, -1);
	dfs2(r2, -1);
	int q1, q2;
	cin >> q1;
	for (int i = 1; i <= q1; ++i)
	{
		cin >> k >> x;
		a[2 * i][0] = -x;
		a[2 * i + 1][0] = x;
		add1(i, k, fa1[k]);
	}
	cin >> q2;
	for (int i = 1; i <= q2; ++i)
	{
		cin >> k >> x;
		a[(q1 + i) * 2][0] = -x;
		a[(q1 + i) * 2 + 1][0] = x;
		add2(i + q1, k, fa2[k]);
	}
	m = (q1 + q2) * 2 + n+5;
	int k2 = (q1 + q2+1) * 2;
	for (int i = 1; i <= n; ++i)
	{
		a[k2 + i][0] = 1;
		a[k2 + i][i] = 1;
	}
	//for (int i = 0; i < 10; ++i)
	//{
		//for (int j = 0; j < 10; ++j)
			//cout << a[i][j] << " ";
		//cout << endl;
	//}
	if (!solve())
		cout << -1 << endl;
	else
		cout << -static_cast<long long>(a[0][0] - 0.1) << endl;
	return 0;
}