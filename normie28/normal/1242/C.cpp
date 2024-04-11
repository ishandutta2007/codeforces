
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
vector <pll> K[40404];
vector <pll> V;
vector <ll> G[22];
bool chk[22], dp[40404], poss[40404];
ll D[22], S[22];
ll A[22], B[22];
ll k, s;
 
void check(ll p, ll x)
{
	vector <pll> X;
	ll i, b, y;
	
	for(i = 1; i <= k; i ++){
		chk[i] = 0;
	}
	
	chk[p] = 1; b |= 1ll << p - 1;
	X.emplace_back(p, x);
	
	for(i = p, y = x; ; ){
		auto it = lower_bound(V.begin(), V.end(), pll(s - S[i] + x, -1));
		if(it == V.end() || it -> first != s - S[i] + x) return;
		x = s - S[i] + x; i = it -> second;
		if(chk[i]) break;
		X.emplace_back(i, x);
		b |= 1ll << i - 1; chk[i] = 1;
	}
	
	if(i != p || x != y) return;
	
	if(K[b].empty()){
		K[b] = X;
		poss[b] = 1;
	}
}
 
void make(ll b)
{
	vector <pll> &X = K[b];
	ll i;
	
	for(i = 0; i < X.size(); i ++){
		A[X[i].first] = X[i].second;
		B[X[i].first] = X[(i + X.size() - 1) % (ll)X.size()].first;
	}
}
 
int main()
{
    fio;
	ll i, j, v;
	
	cin >> k;
	
	for(i = 1; i <= k; i ++){
		cin >> D[i];
		for(j = 0; j < D[i]; j ++){
			cin >> v;
			s += v; S[i] += v;
			G[i].push_back(v);
			V.emplace_back(v, i);
		}
	}
	
	if(s % k){
		cout << "No\n";
		return 0;
	}
	
	s /= k;
	
	sort(V.begin(), V.end());
	
	for(i = 1; i <= k; i ++){
		for(ll &t: G[i]){
			check(i, t);
		}
	}
	
	dp[0] = 1;
	
	for(i = 1; i < (1 << k); i ++){
		for(j = i; !dp[i] && j; j = j - 1 & i){
			if(dp[i - j] && poss[j]) dp[i] = 1;
		}
	}
	
	if(!dp[(1 << k) - 1]){
		cout << "No\n";
		return 0;
	}
	
	for(i = (1 << k) - 1; i; ){
		for(j = i; j; j = j - 1 & i){
			if(dp[i - j] && poss[j]) break;
		}
		make(j); i -= j;
	}
	
	cout << "Yes\n";
	
	for(i = 1; i <= k; i ++){
		cout << A[i] << " " << B[i] << endl;
	}
}