
// Problem : B. Boboniu Walks on Graph
// Contest : Codeforces - Codeforces Round #664 (Div. 1)
// URL : https://codeforces.com/contest/1394/problem/B
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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//

std::vector<int> factorize(int n) {
	std::vector<int> r;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			r.push_back(i);
			do {
				n /= i;
			} while (n % i == 0);
		}
	}
	if (n != 1)
		r.push_back(n);
	return r;
}
 
int pow(int b, int e, int m) {
	int r = 1;
	while (e) {
		if (e & 1)
			r = (long long)r * b % m;
		b = (long long)b * b % m;
		e >>= 1;
	}
	return r;
}
 
int solve(int n, int x) {
	if (x == 2)
		return -1;
	if (n == 1)
		return x - 1;
	int m = n + 1;
	if (factorize(m).size() != 1)
		return -1;
	std::vector<int> p = factorize(n);
	for (auto&& e : p) {
		e = n / e;
	}
	for (int b = x; --b != 1;) {
		if (std::none_of(p.begin(), p.end(), [&](int e) { return pow(b, e, m) == 1; }))
			return b;
	}
	return -1;
}
 
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, x;
	std::cin >> n >> x;
	std::cout << solve(n, x) << '\n';
	return 0;
}