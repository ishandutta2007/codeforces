//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < n; ++i)
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()


using namespace std;

typedef long long ll;
const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5+1;
const int P = 998244353;
const int md = 1e9+7;
const int md2 = 1e9+9;
const int P2 = 883;

int hashes1[maxN], hashes2[maxN], cP[maxN], cP2[maxN];

int mul(int a, int b) {
    return (1LL * a * b) % md;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

void calc(vector<int> s) {
    hashes1[0] = hashes2[0] = s[0];
    cP[0] = cP2[0] = 1;
    for(int i = 1; i < s.size(); ++i) {
        cP[i] = mul(cP[i-1], P);
        cP2[i] = mul(cP2[i-1], P2);
        hashes1[i] = add(mul(hashes1[i-1], P), s[i]);
        hashes2[i] = add(mul(hashes2[i-1], P2), s[i]);
    }
}

pair<int, int> get(int l, int r) {
    if (l > r) return {0, 0};
    if (l == 0) return {hashes1[r], hashes2[r]};
    return {sub(hashes1[r], mul(hashes1[l - 1], cP[r - l + 1])), sub(hashes2[r], mul(hashes2[l-1], cP2[r - l + 1]))};
}

vector<int> pref;
vector<pair<int, int>> w;

pair<pair<int, int>, pair<int, int>> check(int l, int r) {
    int su = pref[r];
    if (l) su -= pref[l - 1];
    if (su == r - l + 1) return {{su, -1}, {-1, -1}};
    pair<int, int> kek = {l, -1};
    int l1 = lower_bound(all(w), kek) - w.begin();
    pair<int, int> kek2 = {r+1,  -1};
    int r1 = upper_bound(all(w), kek2) - w.begin();
    auto hashe = get(l1+1, r1-1);
    return {{su, (w[l1].first - l) % 2}, hashe};
}

void solve() {
    int n; cin >> n;
    string t; cin >> t;
    range(i, n) {
        if (t[i] == '0') {
            if (!w.empty()) w.emplace_back(i, (i - w.back().first) % 2 + 1);
            else w.emplace_back(i, (i + 1) % 2 + 1);
        }
    }
    pref.resize(n, 0);
    pref[0] = t[0] - '0';
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i-1] + (t[i] - '0');
    }
    vector<int> k;
    for(auto p: w) k.push_back(p.second);
    if (!w.empty()) calc(k);
    int q; cin >> q;
    range(_, q) {
        int l1, l2, le; cin >> l1 >> l2 >> le;
        l1--;
        l2--;
        int r1 = l1 + le;
        int r2 = l2 + le;
        r1--;
        r2--;
        if (check(l1, r1) == check(l2, r2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //auto sad = mt19937(2231337);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}