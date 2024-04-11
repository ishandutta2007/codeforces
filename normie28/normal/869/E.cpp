
// Problem : E. The Untended Antiquity
// Contest : Codeforces - Codeforces Round #439 (Div. 2)
// URL : https://codeforces.com/problemset/problem/869/E
// Memory Limit : 512 MB
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
#define DBG(v) cerr << #v << " = " << (v) << endl;
 
const int MxN = 2509;
int dp[MxN + 9][MxN + 9];
 
const int MxQ = (int) 1e5 + 9;
 
int f(const int r, const int c) {
	stack<int> st;
	st.push(0);
	for (int j = 1; j <= c; ++j) {
		const int x = dp[r][j];
		if (x > 0)
			st.push(x);
		else if (x < 0) {
			assert(!st.empty());
			assert(-x == st.top());
			st.pop();
		}
 
	}
	return st.top();
}
 
signed main() {
	fio;
	int n, m, q;
	cin >> n >> m >> q;
 
	for (int i = 1; i <= q; ++i) {
		int type, r1, c1, r2, c2;
		cin >> type >> r1 >> c1 >> r2 >> c2;
		switch (type) {
		case 1:
			for (int r = r1; r <= r2; ++r) {
				assert(dp[r][c1] == 0);
				dp[r][c1] = i;
				assert(dp[r][c2 + 1] == 0);
				dp[r][c2 + 1] = -i;
			}
			break;
		case 2:
			for (int r = r1; r <= r2; ++r) {
				dp[r][c1] = 0;
				dp[r][c2 + 1] = 0;
			}
			break;
		case 3: {
			const bool ok = f(r1, c1) == f(r2, c2);
			cout << (ok ? "Yes" : "No") << '\n';
		}
			break;
		default:
			assert(false);
			break;
		}
	}
	return 0;
}