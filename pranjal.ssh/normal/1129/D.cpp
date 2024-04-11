#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 998244353;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

inline void add(int &x, int y) {x += y; if (x >= inf) x -= inf;}
inline void sub(int &x, int y) {x -= y; if (x < 0) x += inf;}

const int N = 1e5+10;
const int K = 400;
int a[N], v[N], dp[N], last[N], last2[N];
int n, k;

struct block {
    int l, r, off, ans;
    vi F; int *f;
    block(int l, int r): l(l), r(r), off(0), ans(0) {
        F.resize(2*N);
        f = &F[N];
    }
    inline void yo(int i) {
        v[i] = 0 - off;
        add(f[0-off], dp[i-1]);
        add(ans, dp[i-1]);
    }
    inline void upd(int i, int dv) {
        sub(f[v[i]], dp[i-1]);
        if (v[i]+off <= k) sub(ans, dp[i-1]);

        v[i] += dv;

        add(f[v[i]], dp[i-1]);
        if (v[i]+off <= k) add(ans, dp[i-1]);
    }
    inline void inc() {
        sub(ans, f[k - off]);
        off++;
    }
    inline void dec() {
        add(ans, f[k+1-off]);
        off--;
    }
    inline void Add(int val) {
        if (val > 0) {while (val) inc(), val--;}
        else {while (val) dec(), val++;}
    }
};
vector<block> B;

void upd(int l, int r, int v) {
    FOR (it, l, r) {
        if ((it-1) % K == 0 and min(n, it + K - 1) <= r) {
            B[(it-1)/K].Add(v);
            it = min(n, it + K - 1);
        } else {
            B[(it-1)/K].upd(it, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];

    FOR (i, 1, n) {
        if (i == 1 or (i-1) / K != (i-2) / K) {
            B.emplace_back(i, min(n, i+K-1));
        }
    }

    dp[0] = 1;
    B[0].yo(1);
    FOR (i, 1, n) {
        // pr(i);
        if (last[a[i]] == 0) {
            upd(1, i, 1);
        } else if (last2[a[i]] == 0) {
            upd(1, i, 1);
            upd(1, last[a[i]], -2);
        } else {
            upd(1, i, 1);
            upd(1, last2[a[i]], 1);
            upd(1, last[a[i]], -2);
        }
        last2[a[i]] = last[a[i]];
        last[a[i]] = i;
        for (const auto &it: B) {
            add(dp[i], it.ans);
        }
        if (i != n) {
            B[i/K].yo(i+1);
        }
    }

    cout << dp[n] << "\n";
    
    return 0;
}