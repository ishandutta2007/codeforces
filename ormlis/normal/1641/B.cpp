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
const int maxN = 1e6 + 30;
const int LG = 100;

struct FSegTree {
    struct Node {
        pair<int, int> value;

        Node(pair<int, int> _val = {-1, -1}) : value(_val) {}

        void combine(const Node &a, const Node &b) {
            value = max(a.value, b.value);
        }

        void apply(pair<int, int> x) {
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
            t[i + n].apply({v[i], i});
        }
        for (int i = n - 1; i >= 0; --i) t[i].combine(t[i << 1], t[i << 1 | 1]);
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
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    map<int, int> cnt;
    for (auto &x : a) cnt[x]++;
    for (auto &[x, y] : cnt) {
        if (y % 2 == 1) {
            cout << "-1\n";
            return;
        }
    }
    vector<pair<int, int>> ans;
    int add = 0;
    vector<int> answ;
    auto rev = [&](int l, int r) {
        for (int i = l; i < r; ++i) {
            ans.emplace_back(r + add + (i - l), a[i]);
        }
        answ.push_back((r - l) * 2);
        reverse(a.begin() + l, a.begin() + r);
        add += (r - l) * 2;
    };
    for(int i = n - 1; i >= 0; --i) {
        int mx = i;
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[mx]) mx = j;
        }
        if (mx == i) continue;
        if (mx != 0) rev(0, mx + 1);
        rev(0, i + 1);
    }
    for(int l = 0, r = 0; l < n; l = r) {
        while(r < n && a[r] == a[l]) r++;
        assert((r - l) % 2 == 0);
        answ.emplace_back(r - l);
    }
    cout << ans.size() << '\n';
    for(auto &[p, c] : ans) cout << p << ' ' << c << '\n';
    cout << answ.size() << '\n';
    for(auto &x : answ) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}