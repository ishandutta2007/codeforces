
// Problem : F. Bicolored Segments
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
/*
Search the term 'algorithm visualization' in your favorite Search Engine, do you see VisuAlgo in the first page of the search result :)? Next level: Search that term again, but in your native language (if it is not English). Is VisuAlgo still listed in the first page? :). And get ready to be surprised: Search the name of your favorite data structure or algorithm without mentioning the keyword 'animation' or 'visualization'. Is VisuAlgo still listed in the first page? :):).
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define FILE_IN "caps.inp"
#define FILE_OUT "caps.out"
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
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(18101203))
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
#define vi vector<int>
#define bi bigint
#define get geet
#define pll pair<ll,ll>
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll; 
//--------END----------//
const int mod = 998244353, N = 110;
int n, m, k;
int b[N];
 
 
struct Mat {
	ll a[N][N];
	Mat(bool flag = 0) {
		memset(a, 0, sizeof(a));
		if(flag)
			for(int i = 0; i < N; ++i)
				a[i][i] = 1;
	}
	ll* operator[](unsigned id) {
		return a[id];
	}
	Mat operator*(Mat &rhs) {
		Mat res;
		for(int i = 0; i < k; ++i) {
			for(int j = 0; j < k; ++j) {
				for(int p = 0; p < k; ++p) {
					res[i][j] = (res[i][j] + a[i][p] * rhs[p][j]) % (mod - 1);
				}
			}
		}
		return res;
	}
}base;
 
Mat Mat_qp(Mat a, ll n) {
	Mat res(1);
	while(n) {
		if(n & 1)
			res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}
 
ll qp(ll a, ll n, ll m = mod) {
	ll res = 1;
	while(n) {
		if(n & 1)
			res = res * a % m;
		a = a * a % m;
		n >>= 1;
	}
	return res;
}
 
ll BSGS(ll A, ll B, ll C) { //find minium x satisfy A ** x % C = B % C 
	map<ll, ll> mp;
	if(A % C == 0) return -1;
	ll m = ceil(sqrt(C)); //x = i * m - j, A ** (i * m - j) = B, A ** (i * m) = B * A ** j
	ll ans = B % C;
	for(int j = 0; j <= m; ++j) { //enum j
		mp[ans] = j;
		ans = ans * A % C;		
	}
	ll t = qp(A, m, C);
	ans = t;
	for(int i = 1; i <= m; ++i) { //enum i, find j
		if(mp.count(ans)) 
			return ((i * m - mp[ans]) % C + C) % C;
		ans = ans * t % mod;
	}
	return -1;
}
 
ll exgcd(ll a, ll b, ll &x, ll &y) {//x, y must be reference, ax + by = gcd(a, b)
    if(b == 0) {
    	x = 1, y = 0;
    	return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y, y = t - (a / b) * y;
    return d; //d= gcd(a, b)
}
 
/*
3 ** p = mod;
t = jar[0][0];
3 ** (x * t) = 3 ** p
x * t = p
t * x + 998244352 * y = gcd(t, 998244352)
*/
 
ll solve(ll t, ll p) {
	ll x, y;
	ll d = exgcd(t, mod - 1, x, y);
	if(p % d) return -1;
	x = ((x * p / d) % (mod - 1) + (mod - 1)) % (mod - 1);
	return qp(3, x, mod);
}
 
 
int main() {
    fio;
    cin>>k;
	for(int i = 0; i < k; ++i) {
	    cin>>base[0][i];
		base[i + 1][i] = 1;
	}
	cin>>n>>m;
	Mat jar = Mat_qp(base, n - k);
	cout<<solve(jar[0][0], BSGS(3, m, mod));
}