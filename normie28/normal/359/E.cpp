
// Problem : E. Neatness
// Contest : Codeforces - Codeforces Round #209 (Div. 2)
// URL : https://codeforces.com/contest/359/problem/E
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
 
const int maxn= 510;
int n , m;
bool mark[maxn][maxn], a[maxn][maxn];
pair <int , int > par[maxn][maxn];
vector < string > v;
 
 
void dfs1(int x, int y)
{
	mark[x][y] = 1;
	if (!a[x][y])
		v.push_back("1");
	a[x][y] = 1;
	for (int i = x + 1; i < n; i ++)
		if (a[i][y] == 1 && !mark[x + 1][y])
		{
			v.push_back("D");
			dfs1(x + 1, y);
			v.push_back("U");
		}
	for (int i = 0; i < x; i ++)
		if (a[i][y] == 1 && !mark[x - 1][y])
		{
			v.push_back("U");
			dfs1(x - 1, y);
			v.push_back("D");
		}
	for (int j = y + 1; j <  n; j ++)
		if (a[x][j] == 1 && !mark[x][y + 1])
		{
			v.push_back("R");
			dfs1(x, y + 1);
			v.push_back("L");
		}
 
	for (int j = 0; j < y; j ++)
		if (a[x][j] == 1 && !mark[x][y - 1])
		{
			v.push_back("L");
			dfs1(x, y - 1);
			v.push_back("R");
		}
	return;
}
 
void dfs2(int x, int y)
{
	a[x][y] = 0;
	if (a[x + 1][y] == 1)
	{
		v.push_back("D");
		dfs2(x + 1, y);
		v.push_back("U");
	}
	if (a[x - 1][y] == 1)
	{
		v.push_back("U");
		dfs2(x - 1, y);
		v.push_back("D");
	}
	if (a[x][y + 1] == 1)
	{
		v.push_back("R");
		dfs2(x, y + 1);
		v.push_back("L");
	}
 
	if (a[x][y - 1] == 1)
	{
		v.push_back("L");
		dfs2(x, y - 1);
		v.push_back("R");
	}
	v.push_back("2");
}
 
int main()
{
	fio;
	int x , y;
	cin >> n >> x >> y;
	for (int i = 0 ; i < n; i ++)
		for (int j =0 ; j < n; j ++)
				cin >> a[i][j];
	dfs1(x - 1 ,y - 1);
	dfs2(x - 1, y -1);
	for (int i = 0 ; i < n; i ++)
		for (int j =0 ; j <  n; j ++)
			if (a[i][j])
			{
				cout << "NO" << endl;
				return 0;
			}
	cout << "YES" << endl;
	for (int i = 0 ; i < v.size() ; i ++)
		cout << v[i];
}