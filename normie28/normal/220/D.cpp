 
// Problem : B. Game with modulo
// Contest : Codeforces - Codeforces Round #534 (Div. 1)
// URL : https://codeforces.com/contest/1103/problem/B
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
#define bi BigInt
typedef long long ll;
#define gcd gcddd
//---------END-------//
 
const ll mod = 1e9L + 7;
const ll inv2 = (mod + 1) / 2;
const ll inv3 = (mod + 1) / 3;
const ll inv6 = (mod + 1) / 6;
 
ll cn2(ll n) {
	return n * (n - 1) % mod * inv2 % mod;
}
ll cn3(ll n) {
	return n * (n - 1) % mod * (n - 2) * inv6 % mod;
}
 
const int N = 4e3L + 11;
int gcd[N][N];
 
int main() {
    fio;
	for(int k = 1; k < N; k ++)
		for(int i = 0; i < N; i += k)
			for(int j = 0; j < N; j += k)
				gcd[i][j] = k;
 
	int n, m; cin >> n >> m;
 
	ll res = 0;
	for(int i = 0; i < 2; i ++)
		for(int j = 0; j < 2; j ++) {
			ll c[4];
			for(int s = 0; s < 2; s ++)
				for(int t = 0; t < 2; t ++) {
					ll a = (((i ^ s) & 1) ? (n + 1) / 2 : n / 2 + 1);
					ll b = (((j ^ t) & 1) ? (m + 1) / 2 : m / 2 + 1);
					c[s * 2 + t] = a * b;
				}
			c[0] --;
 
			ll tmp = 0;
			for(int s = 0; s < 4; s ++)
				for(int t = s; t < 4; t ++) {
					int x = (s >> 1) * (t & 1) + (s & 1) * (t >> 1);
					if(x % 2 == 0) {
						if(s == t)
							tmp += cn2(c[s]);
						else
							tmp += c[s] * c[t];
						tmp %= mod;
					}
				}
 
			ll a = ((i & 1) ? (n + 1) / 2 : n / 2 + 1);
			ll b = ((j & 1) ? (m + 1) / 2 : m / 2 + 1);
			res += tmp * a * b;
			res %= mod;
		}
	res = res * inv3 % mod;
 
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= m; j ++) if((i > 0 || j > 0) && /*__gcd(i, j) == 1*/ gcd[i][j] == 1) {
			for(int k = 0; k * i <= n && k * j <= m; k ++) {
				ll t = ll(n - k * i + 1) * (m - k * j + 1);
				if((k + 1) * i <= n && (k + 1) * j <= m)
					t -= ll(n - (k + 1) * i + 1) * (m - (k + 1) * j + 1);
				res -= t * cn2(k);
				if(i > 0 && j > 0)
					res -= t * cn2(k);
				res %= mod;
			}
		}
	cout << (res * 6 % mod + mod) % mod << '\n';
}