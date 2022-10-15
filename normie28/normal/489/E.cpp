
// Problem : E. Hiking
// Contest : Codeforces - Codeforces Round #277.5 (Div. 2)
// URL : https://codeforces.com/problemset/problem/489/E
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
#define pb push_back
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
const double EPS =  1e-9;
const long long MAXN = 1e6 + 1;
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j,l;
vector <double> dp (MAXN);
vector <int> p (MAXN);
int x[MAXN];
int b[MAXN];
bool check(double m) {
	fill(dp.begin() + 1, dp.end(), MOD);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j] + sqrt(abs(x[i] - x[j] - l)) - m * b[i] < dp[i]) {
				dp[i] = dp[j] + sqrt(abs(x[i] - x[j] - l)) - m * b[i];
				p[i] = j;				
			}
		}		
	}
	return dp[n] < 0.0;
}
int main() {
    fio;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
      cin >> x[i] >> b[i];
    }
    double l = 0, r = 1000000;
	while(r - l > EPS) {
		double mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	int kek = (check(l) ? 0 : check(r));
	vector <int> ans;
	int tmp = n;
	while (tmp) {
		ans.pb(tmp);
		tmp = p[tmp];
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[ans.size() - i - 1] << ' ';
	}
}