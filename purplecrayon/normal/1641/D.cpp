#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;
const int INF = 2e9+10;

// you can keep a pointer of the possible prefixes to consider
// if there is at least one good one, shrink the possible prefixes until you find the candidate

typedef uint64_t ull;
static int C; // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
	bool operator==(A o){ return ull(*this) == ull(o); }
	bool operator!=(A o){ return ull(*this) != ull(o); }
};
typedef A<1000000007, A<1000000009, A<998244353, unsigned>>> H;

#include<bits/extc++.h>
struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

struct Hash {
	H h;
	
    Hash(): h() {}
    void push_back(int x) {
        h = h * C + x;
    }
	explicit operator ull() { return ull(h); }
};
#include <sys/time.h>
void pre_hashes(){ //call pre before testcases
	timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);
}

struct IncExc {
    int n;
    hash_map<ull, int> cnt; // make faster with hashing?

    void add(const vector<int>& v, int delta) {
        n += delta;

        const int M = sz(v);
        for (int m = 1; m < (1 << M); m++) {
            int x = __builtin_popcount(m) & 1 ? delta : -delta;
            Hash a;
            for (int i = 0; i < M; i++) if ((m >> i) & 1)
                a.push_back(v[i]);

            cnt[ull(a)] += x;
        }
    }
    void add(const vector<int>& v) {
        add(v, +1);
    }
    void er(const vector<int>& v) {
        add(v, -1);
    }
    int qry(const vector<int>& v) { // number of sets with positive intersection
        const int M = sz(v);
        int ans = 0;
        for (int m = 1; m < (1 << M); m++) {
            Hash a;
            for (int i = 0; i < M; i++) if ((m >> i) & 1)
                a.push_back(v[i]);

            ans += cnt[ull(a)];
        }
        return ans;

    }
    size_t size() {
        return n;
    }
} cand;

bool good(const vector<int>& a, const vector<int>& b) {
    set<int> s(a.begin(), a.end());
    for (int x : b) if (s.count(x)) return false;
    return true;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> cost(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(m);
        for (auto& x : a[i]) cin >> x;
        sort(a[i].begin(), a[i].end());
        cin >> cost[i];
    }
    vector<int> p(n); std::iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return cost[i] < cost[j];
    });

    int ans = INF;
    int last = 0;
    for (int i = 1; i < n; i++) {
        if (last == i-1) {
            cand.add(a[p[i-1]]);
            last = i;
        }
        if (cand.qry(a[p[i]]) < sz(cand)) {
            while (cand.qry(a[p[i]]) < sz(cand)) {
                if (last < i) {
                    cand.er(a[p[last]]);
                }
                last--;
            }
            last++;
            if (good(a[p[i]], a[p[last]])) 
                ans = min(ans, cost[p[i]] + cost[p[last]]);
        }
    }
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre_hashes();
    int T = 1;
    // cin >> T;
    while (T--) solve();
}