#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e2+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 95542721, MAXK = 1e2+10,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;


struct Tree {
	typedef ll T;
	static constexpr T unit = INF;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
        e++;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    //k*2+1 is the range
    //i-k is the cost
    Tree t(n);

    vector<vector<pair<int, ll>>> a(n); //starting point, cost
    for (int i = 0; i < n; i++) if (s[i] == '1') {
        int st = i-k, cost = i+1;
        a[min(n-1, i+k)].push_back({st, cost});
    }

    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = i+1 + (i?dp[i-1]:0);
        for (auto c : a[i]) {
            ll cur = 0;
            if (c.first > 0) cur = t.query(c.first-1, i-1);
            dp[i] = min(dp[i], cur+c.second);
        }
        t.update(i, dp[i]);
    }
    cout << dp[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}