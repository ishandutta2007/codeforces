
// Problem : C. Splitting the Uniqueness
// Contest : Codeforces - Codeforces Round #180 (Div. 1)
// URL : https://codeforces.com/problemset/problem/297/C
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
struct node{
	int x, i;
	} a[100020], b[100020], c[100020];
bool f(node a, node b){ return a.x < b.x; }
bool g(node a, node b){ return a.i < b.i; }
int main() {
	fio;
	int i, n, j;
	cin >> n;
	cout << "YES\n";
	for(i = 1; i <= n; i++){
		cin >> a[i].x, a[i].i = i , a[i].x += 2;
	}
	sort(a+1, a+n+1, f);
	for(i = 1; i <= n/3; i++) b[i].i = c[i].i = a[i].i, b[i].x = i, c[i].x = a[i].x - i;
	for(i = 1+n/3; i <= (n+n)/3; i++) b[i].i = c[i].i = a[i].i, c[i].x = i, b[i].x = a[i].x - i;
	for(i = 1+(n+n)/3, j = i; i <= n; i++) b[i].i = c[i].i = a[i].i, c[i].x = n-i+1, b[i].x = a[i].x - c[i].x;
	sort(b+1, b+n+1, g);
	sort(c+1, c+n+1, g);
	for(i = 1; i <= n; i++) cout << b[i].x-1 << " "; cout << endl;
	for(i = 1; i <= n; i++) cout << c[i].x-1 << " "; cout << endl;
}