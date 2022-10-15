
// Problem : F. Sonya and Bitwise OR
// Contest : Codeforces - Codeforces Round #495 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1004/F
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define INF (1ll<<58)
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
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef std::pair<ll,ll> pll;
typedef std::string str;
//---------END-------//
 
const int M = 1e9 + 7;
const int MX = 2e5;
 
int l[MX + 1], r[MX + 1], rg[MX + 1], comp[MX + 1], prob[MX + 1];
 
int add(int a, int b) {
	return a + b >= M ? a + b - M : a + b;
}
 
int sub(int a, int b) {
	return a - b < 0 ? a - b + M : a - b;
}
 
int mul(int a, int b) {
	return (long long)a * b % M;
}
 
int modpow(int a, int b) {
	if (!b) return 1;
	if (b % 2) return mul(a, modpow(a, b - 1));
	int tmp = modpow(a, b / 2);
	return mul(tmp, tmp);
}
 
int getprob(int a) {
	int lb = max({l[a - 1], l[a], l[a + 1]});
	int ub = min({r[a - 1], r[a], r[a + 1]});
	int res = sub(add(comp[a], comp[a + 1]), mul(max(0, ub - lb + 1), modpow(mul(rg[a - 1], mul(rg[a], rg[a + 1])), M - 2)));
	return sub(1, res);
}
 
int main() {
    fio;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> r[i];
		rg[i] = r[i] - l[i] + 1;
	}
 
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		int lb = max(l[i], l[i - 1]);
		int ub = min(r[i], r[i - 1]);
 
		comp[i] = mul(max(0, ub - lb + 1), modpow(mul(rg[i], rg[i - 1]), M - 2));
		prob[i] = sub(1, comp[i]);
		sum = add(sum, prob[i]);
	}
 
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = add(res, mul(prob[i], sub(sum, prob[i])));
		res = add(res, prob[i]);
		if (i > 1) {
			res = sub(res, mul(prob[i], prob[i - 1]));
			res = add(res, getprob(i - 1));
		}
		if (i < n) {
			res = sub(res, mul(prob[i], prob[i + 1]));
			res = add(res, getprob(i));
		}
	}
	cout << res << '\n';
}