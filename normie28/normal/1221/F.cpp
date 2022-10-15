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
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long ll; 
//--------END----------//
using namespace std;
 
typedef unsigned int uint;
typedef unsigned long long ull;
 
vector<pair<long long,long long>> t;
uint n;
 
inline void build() {
	for (uint i = n-1; i; i--) {
		t[i].second = max(t[i<<1].second, t[i<<1|1].second);
	}
}
 
inline void update(uint p, long long c) {
	p += n;
	t[p].first += c;
	t[p].second += c;
	for (p >>= 1; p; p >>= 1) {
		t[p].first += c;
		t[p].second = max(t[p<<1].second, t[p<<1].first+t[p<<1|1].second); 
	}
}
 
inline pair<uint,long long> maxsum(uint l) {
	l += n;
	uint lpos = 0, rpos = 0;
	long long lsum = 0, lans = 0, rans = 0;
	for (uint r = n<<1; l < r; l >>= 1, r >>= 1) {
		if (l&1) {
			if (lans < lsum+t[l].second) {
				lans = lsum+t[l].second;
				lpos = l;
			};
			lsum += t[l].first;
			l++;
		}
		if (r&1) {
			r--;
			if (t[r].second < t[r].first+rans) {
				rans += t[r].first;
			}
			else {
				rans = t[r].second;
				rpos = r;
			}
		}
	}
	if (lans < lsum+rans) {
		return {rpos, lsum+rans};
	}
	else {
		return {lpos, lans};
	}
}
 
inline uint getmaxpos(uint p) {
	while (p < n) {
		p = p<<1|(t[p<<1].second < t[p<<1].first+t[p<<1|1].second);
	}
	return p;
}
 
int main() {
    fio;
	cin >> n;
	vector<tuple<uint,uint,int>> pts; pts.reserve(n);
	vector<uint> xs; xs.reserve(n);
	for (uint i = 0; i < n; i++) {
		uint x, y; int c;
		cin >> x >> y >> c;
		if (x > y) { swap(x, y); }
		pts.emplace_back(y, x, c);
		xs.push_back(x);
	}
 
	sort(pts.begin(), pts.end(), [](auto &p1, auto &p2) {
		return get<0>(p1) < get<0>(p2);
	});
	sort(xs.begin(), xs.end());
	n = unique(xs.begin(), xs.end()) - xs.begin();
	xs.resize(n);
	t.resize(2*n);
	for (uint i = 0; i < n; i++) {
		t[n+i].second = xs[n-1-i];
	}
	build();
 
	uint bestx, besty;
	long long ans = 0;
	for (auto it = pts.begin(); it != pts.end(); ) {
		uint y = get<0>(*it);
		for (; it != pts.end() && get<0>(*it) == y; it++) {
			uint pos = xs.end() - upper_bound(xs.begin(), xs.end(), get<1>(*it));
			update(pos , get<2>(*it));
		}
		uint pos =  xs.end() - upper_bound(xs.begin(), xs.end(), y);
		auto ret = maxsum(pos);
		if (ans < ret.second-y) {
			bestx = getmaxpos(ret.first);
			besty = y;
			ans = ret.second-y;
		}
	}
	cout << ans << endl;	
	if (ans == 0) { bestx = besty = xs.back()+1; }
	else { bestx = xs[2*n-1-bestx]; }
	cout << bestx << ' ' << bestx << ' ' << besty << ' ' << besty << endl;
}