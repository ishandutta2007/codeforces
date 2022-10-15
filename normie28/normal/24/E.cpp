
// Problem : E. Berland collider
// Contest : Codeforces - Codeforces Beta Round #24
// URL : https://codeforces.com/problemset/problem/24/E
// Memory Limit : 256 MB
// Time Limit : 1500 ms
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
#define pb push_back
#define mkp make_pair
#define p1 first
#define p2 second.first
#define p3 second.second
#define X first
#define Y second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define smax(a,b) a=max(a,b)
#define modi(a,b) ((a%b+b)%b)
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef pair <ll,ll> pll;
//---------END-------//
const ll maxn=5e5+5;	const ll bghs=1e9+7; const ll INF=1e10;
ll n,x[maxn],v[maxn];
bool check(long double mid)
{
	long double jvb=-1e40;
	for(ll i=0;i<n;i++) 
	{
			if (v[i] > 0) smax(jvb,x[i] + mid*v[i]);
			else if (x[i] + mid*v[i] <= jvb) return true;
	}
	return false;
}
int main () 
{
	fio;
	cin >> n;
	for (ll i=0;i<n;i++) 
		cin >> x[i] >> v[i];
	long double l = 0, r = INF;
	for(ll i=0;i<100;i++) 
	{
		long double mid   = (l+r)/2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	double khar=-1;
	if (r >= INF) cout << setprecision(18) << fixed << khar <<endl;
	else cout << setprecision(18) << fixed << (l+r)/2 <<endl;
}