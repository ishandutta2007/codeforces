
// Problem : E. Tavas and Pashmaks
// Contest : Codeforces - Codeforces Round #299 (Div. 2)
// URL : https://codeforces.com/problemset/problem/535/E
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "sort.in"
#define FILE_OUT "sort.out"
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
#define index indexx
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
ll n,m,i,j,k,t,u,v,arr[100001];
string s;
ordered_set se;
struct cmp
{
	int operator()(ll a, ll b)
	{
		return a>b;
	}
};
priority_queue<ll,vector<ll>,cmp> buc[26];
int main()
{
//	ofile;
	fio;
	cin>>n>>s;
	for (i=0;i<n;i++)
	{
		se.insert(i);
		buc[s[i]-97].push(i);
	}
	for (i=0;i<n;i++)
	{
		k=buc[(int)s[n-1-i]-97].top();
		buc[int(s[n-1-i]-97)].pop();
		u+=se.order_of_key(k);
		se.erase(k);
	}
	cout<<u;
}