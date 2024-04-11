//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define FILE_IN "polygon.inp"
#define FILE_OUT "polygon.out"
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
#define vi vector<int>
#define bi BigInt
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll;
const int N = 4e6 + 7, M = 1e9 + 7;
int n, a[N], m, h[22];
ll sm1[22], sm2[22];
void calc(int s, int e, int h) {
	if (s == e)return;
	calc(s, (s + e) / 2, h - 1);
	calc((s + e) / 2 + 1, e, h - 1);
	int j = s;
 
	for (int i = (s + e) / 2 + 1; i <= e; i++) {
		while (j <= (s + e) / 2 && a[j] < a[i])j++;
		sm1[h] += j - s;
		while (j <= (s + e) / 2 && a[j] == a[i])j++;
		sm2[h] += (s + e) / 2 - j + 1;
	}
	vector<int>nw;
	int i = s;
	j = (s + e) / 2 + 1;
 
	while (i <= (s + e) / 2 && j <= e) {
		if (a[i] <= a[j])nw.push_back(a[i]), i++;
		else nw.push_back(a[j]), j++;
	}
	while (i <= (s + e) / 2)nw.push_back(a[i++]);
	while (j <= e)nw.push_back(a[j++]);
	for (int i = s; i <= e; i++)a[i] = nw[i - s];
 
}
int main() {
 fio;
 cin>>n;
	for (int i = 1; i <= (1 << n); i++) cin>>a[i];
	calc( 1, 1 << n, n);
	cin>>m;
	for (int q, i = 0; i < m; i++) {
	    cin>>q;
		long long ans = 0;
		for (int j = 1; j <= n; j++) {
			if (j <= q)h[j] ^= 1;
			if (h[j])ans += sm1[j];
			else ans += sm2[j];
		}
		cout<<ans<<endl;
 
	}
 
}