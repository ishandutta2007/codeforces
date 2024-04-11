
// Problem : E. Pentagon
// Contest : Codeforces - Codeforces Beta Round #48
// URL : https://codeforces.com/contest/51/problem/E
// Memory Limit : 256 MB
// Time Limit : 10000 ms
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
const int MN = 1 << 10;
long long m1[MN][MN], m2[MN][MN], m3[MN][MN], m5[MN][MN];
void mul(int n, long long a[MN][MN], long long b[MN][MN], long long res[MN][MN])
{
	for (int i = 0; i < n; ++i)
		for (int k = i; k < n; ++k)
			for (int l = 0; l < n; ++l)
				res[i][k] += a[i][l] * b[l][k];
  for (int i = 0; i < n; ++i)
    for (int k = 0; k < i; ++k)
      res[i][k] = res[k][i];
}
int main()
{
	fio;
	int n, m; 
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin>>a>>b;
		a--;
		b--;
		m1[a][b] = m1[b][a] = 1;
	}
	mul(n, m1, m1, m2);
	mul(n, m1, m2, m3);
	mul(n, m2, m3, m5);
	long long a = 0, b = 0, c = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
			a += m1[i][k] * m2[i][k];
		b += m5[i][i];
		c += m2[i][i] * m3[i][i];
	}
	long long res = (b - c * 5 + 5 * a) / 10;
	cout<<res<<endl;
}