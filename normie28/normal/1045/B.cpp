
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
using namespace std;
typedef bool boolean;
 
#define ull unsigned long long
 
const int N = 2e5 + 5;
const ull base = 1e9 + 7;
 
int n, M;
int ar[N];
int cr[N];
ull ph[N], sh[N], pb[N];
 
int add(int a, int b) {
	return ((a += b) >= M) ? (a - M) : (a);
}
 
inline void init() {
	scanf("%d%d", &n, &M);
	for (int i = 1; i <= n; i++)
		scanf("%d", ar + i);
}
 
ull fquery(int l, int r) {	// forward
	if (l > r)
		return 0;
	return ph[r] - ph[l - 1] * pb[r - l + 1];
}
 
ull rquery(int l, int r) {	// backward
	if (l > r)
		return 0;
	return sh[l] - sh[r + 1] * pb[r - l + 1];
}
 
boolean ispar(int l, int r) {
	return fquery(l, r) == rquery(l, r);
}
 
vector<int> vec;
 
inline void solve() {
	ph[0] = 0, sh[n] = 0, pb[0] = 1;
	for (int i = 1; i < n; i++)
		ph[i] = ph[i - 1] * base + (cr[i] = ar[i + 1] - ar[i]);
	for (int i = n - 1; i; i--)
		sh[i] = sh[i + 1] * base + cr[i];
	for (int i = 1; i < n; i++)
		pb[i] = pb[i - 1] * base;
 
	for (int i = 1, x; i < n; i++) {
		x = ar[1] + ar[i];
//		if (x >= M)
//			break;
		if (add(ar[i + 1], ar[n]) == x && ispar(1, i - 1) && ispar(i + 1, n - 1))
			vec.push_back(x);
	}
	int x = add(ar[1], ar[n]);
	if ((x <= ar[1] || x >= ar[n]) && ispar(1, n - 1))
		vec.push_back(x);
	printf("%d\n", (signed) vec.size());
	sort(vec.begin(), vec.end());
	for (int i = 0; i < (signed) vec.size(); i++)
		printf("%d ", vec[i]);
	putchar('\n');
}
 
int main() {
	init();
	solve();
	return 0;
}