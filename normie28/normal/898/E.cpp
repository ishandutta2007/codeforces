#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define pii pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
priority_queue<ll> nsq, sq;
 
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll a; cin >> a;
		double p = sqrt(a);
		if ((ll)p * (ll)p == a)
		{
			if (a == 0)
				sq.push(-2);
			else
				sq.push(-1);
		}
		else
		{
			ll d = floor(p), u = ceil(p);
			nsq.push(-min(a - d * d, u * u - a));
		}
	}
 
	ll ans = 0;
	n /= 2;
 
	while (nsq.size() > n) {
		ans -= nsq.top(); nsq.pop();
	}
 
	while (sq.size() > n) {
		ans -= sq.top(); sq.pop();
	}
 
	cout << ans << "\n";
}