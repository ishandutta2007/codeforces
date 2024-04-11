
// Problem : C. Hongcow Buys a Deck of Cards
// Contest : Codeforces - Codeforces Round #385 (Div. 1)
// URL : https://codeforces.com/problemset/problem/744/C
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
typedef pair <char, pii> pcp;
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N = 16, MSK = (1LL << N), K = 16 * 16;
int n, res = (int)1e15, dp[MSK][K];
pcp ar[N];
 
int32_t main() {
	fio;
	int a = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second.first >> ar[i].second.second;
		a += ar[i].second.first;
		b += ar[i].second.second;
	}
	
	for (int i = 0; i < MSK; i++)
		fill(dp[i], dp[i] + K, -(int)1e9);
	dp[0][0] = 0;
	
	for (int msk = 1; msk < (1LL << n); msk++)
		for (int s = 0; s < n * n; s++) {
			int A = 0, B = 0;
			for (int i = 0; i < n; i++)
				if (msk & (1LL << i))
					A += (ar[i].first == 'R');
			B = __builtin_popcount(msk) - A;
			
			for (int i = 0; i < n; i++)
				if (msk & (1LL << i)) {
					if (ar[i].first == 'R') {
						int x = min(ar[i].second.first, A - 1), y = min(ar[i].second.second, B);
						if (s >= x)
							dp[msk][s] = max(dp[msk][s], dp[msk ^ (1LL << i)][s - x] + y);
					}
					else {
						int x = min(ar[i].second.first, A), y = min(ar[i].second.second, B - 1);
						if (s >= x)
							dp[msk][s] = max(dp[msk][s], dp[msk ^ (1LL << i)][s - x] + y);
					}	
				}
		}
	
	for (int j = 0; j < n * n; j++) {
		int A = a - j, B = b - dp[(1LL << n) - 1][j];
		res = min(res, max(A, B));
	}
	cout << res + n << endl;
}