
// Problem : E. Divisor Tree
// Contest : Codeforces - Codeforces Round #196 (Div. 2)
// URL : https://codeforces.com/problemset/problem/337/E
// Memory Limit : 256 MB
// Time Limit : 500 ms
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
vector<pair<ll, int> > v;
int dp[8][1 << 8][3];
int calc(int i, int mask, int roots) {
	roots = min(roots, 2);
	if (i == n)
		return roots != 1;
	int &ret = dp[i][mask][roots];
	if (ret != -1)
		return ret;
	ret = 1e9;
	for (int take = mask; take >= 0; take = (take - 1)&mask) {
		int cur = take | (1 << i);
		bool can = true;
		ll num = v[i].first;
		int cost = v[i].second;
		if (cost != 1)
			++cost;
		for (int j = i + 1; j < n; ++j)
			if (((cur >> j) & 1)) {
				if (num%v[j].first) {
					can = false;
					break;
				}
				num /= v[j].first;
				cost -= v[j].second;
			}
		if (can)
			ret = min(ret, cost + calc(i + 1, (mask^take)&~(1 << i), roots + ((mask >> i) & 1)));
		if (take == 0)
			break;
	}
	return ret;
}
int main()
{
	fio;
	cin >> n;
	v.resize(n);
	for (auto &x : v) {
		cin >> x.first;
		ll n = x.first;
		for (ll i = 2; i*i <= n; ++i) {
			while (n%i == 0) {
				++x.second;
				n /= i;
			}
		}
		if (n != 1)
			++x.second;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	memset(dp, -1, sizeof(dp));
	int res = calc(0, (1 << n) - 1, 0);
	cout<<res;
}