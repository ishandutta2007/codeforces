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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 5e4 + 5;
const int LG = 19;

void solve() {
    int q;
    cin >> q;
    string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    vector<string> to = {
            "What are you doing while sending \"",
            "\"? Are you busy? Will you send \"",
            "\"?"};
    int N = 1e5 + 5;
    vector<ll> len(N);
    len[0] = f0.size();
    int w = to[0].size() + to[1].size() + to[2].size();
    for (int i = 1; i < N; ++i) {
        len[i] = min(len[i - 1] * 2 + w, INF);
    }
    rep(_, q) {
        int n1;
        ll k1;
        cin >> n1 >> k1;
        function<char(int, ll)> go = [&](int n, ll k) {
            if (len[n] <= k) return '.';
            if (n == 0) {
                return f0[k];
            }
            if (k < (int) to[0].size()) return to[0][k];
            k -= (int) to[0].size();
            if (k < len[n - 1]) return go(n - 1, k);
            k -= len[n - 1];
            if (k < to[1].size()) return to[1][k];
            k -= (int) to[1].size();
            if (k < len[n - 1]) return go(n - 1, k);
            k -= len[n - 1];
            assert(k < (int)to[2].size());
            return to[2][k];
        };
        cout << go(n1, k1 - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}