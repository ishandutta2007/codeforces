#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 2e5 + 20;
const int LG = 30;

struct FSegTree {
    struct Node {
        int value;

        Node(int _val = INFi) : value(_val) {}

        void combine(const Node &a, const Node &b) {
            value = min(a.value, b.value);
        }

        void apply(int x) {
            value = x;
        }
    };

    Node combine(const Node &a, const Node &b) {
        Node res;
        res.combine(a, b);
        return res;
    }

    vector<Node> t;
    int n;

    void build(int k) {
        n = k;
        t.resize(n * 2 + 2);
    }

    template<typename T>
    void build(vector<T> &v) {
        n = v.size();
        t.resize(n * 2 + 2);
        range(i, n) {
            t[i + n].apply(v[i]);
        }
        for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
    }

    void upd(int i, int x) {
        for (t[i += n].apply(x); i > 1; i >>= 1) t[i >> 1].combine(t[i], t[i ^ 1]);
    }

    // [l, r)
    Node get(int l, int r) {
        Node result;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result = combine(result, t[l++]);
            if (r & 1) result = combine(result, t[--r]);
        }
        return result;
    }
};


void solve() {
    int n; cin >> n;
    vi p(n);
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]--;
    p.push_back(0);
    vector<ar<int, 2>> dp(n, {INFi, INFi});
    vi lowL(n), lowR(n), bigL(n), bigR(n);
    rep(i, n) {
        lowL[i] = bigL[i] = i;
        if (i) {
            if (p[i - 1] > p[i]) lowL[i] = lowL[i - 1];
            else bigL[i] = bigL[i - 1];
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        bigR[i] = lowR[i] = i;
        if (i + 1 < n) {
            if (p[i + 1] > p[i]) bigR[i] = bigR[i + 1];
            else lowR[i] = lowR[i + 1];
        }
    }
    vi minL(n);
    vector<FSegTree> have(2);
    rep(i, 2) have[i].build(n);
    vector<int> uk(2);
    ll ans = 0;
    rep(i, n) {
        {
            minL[i] = min(bigL[i], lowL[i]) - 1;
        }
        {
            // low, big -> 0
            int j = lowL[i];
            while(uk[0] < j - 1) {
                have[0].upd(p[uk[0]], INFi);
                uk[0]++;
            }
            minL[i] = min(minL[i], have[0].get(0, n).value);
            dp[i][0] = min(j, have[0].get(0, p[i + 1]).value);
        }
        {
            // big, low -> 1
            int j = bigL[i];
            while(uk[1] < j - 1) {
                have[1].upd(p[uk[1]], INFi);
                uk[1]++;
            }
            minL[i] = min(minL[i], have[1].get(0, n).value);
            dp[i][1] = min(j, have[1].get(p[i + 1], n).value);
        }
        have[0].upd(p[i], dp[i][1]);
        have[1].upd(p[i], dp[i][0]);
        minL[i] = max(minL[i], 0);
        ans += i - minL[i] + 1;
    }
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}