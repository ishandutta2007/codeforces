#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e6 + 1500;
const int md2 = 998244353;
const int md = 1e9 + 7;


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}


int rev(int a) {
    return binpow(a, md - 2);
}

struct ZFunc {
    vector<int> z{};

    void build(string &s) {
        int n = s.size();
        z.resize(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (z[i] + i < n && s[z[i] + i] == s[z[i]]) {
                z[i]++;
            }
            if (z[i] + i > r) {
                l = i;
                r = z[i] + i;
            }
        }
        z[0] = n;
    }
};

int K;
string s0, t;
string w2;
int answer = 0;
int psum[26][maxN];
int st2[maxN];

void solve(int start, int step, int k) {
    if (k > K) return;
    int cnt = (int) w2.size() - start;
    cnt = (cnt + step - 1) / step;
    if (cnt == 1) {
        int c = w2[start] - 'a';
        int cur = psum[c][K];
        if (k) cur = sub(cur, psum[c][k - 1]);
        cur = mul(cur, st2[K]);
        answer = add(answer, cur);
        return;
    }
    range(e, 2) {
        bool bad = false;
        for (int i = start + e * step; i < (int) w2.size(); i += step * 2) {
            if (w2[i] != t[k]) {
                bad = true;
                break;
            }
        }
        if (bad) continue;
        solve(start + (1 - e) * step, step * 2, k + 1);
    }
}

void solve() {
    st2[0] = 1;
    for(int i = 1; i < maxN; ++i) {
        st2[i] = mul(st2[i-1], 2);
    }
    int n, q;
    cin >> n >> q;
    cin >> s0 >> t;
    K = -1;
    vector<string> w(q);
    vector<int> k(q);
    range(i, q) {
        cin >> k[i] >> w[i];
    }
    vector<int> order(q);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) {
        return k[i] < k[j];
    });
    vector<int> ans(q);
    for (auto &i : order) {
        ZFunc z;
        string W = s0 + "#" + w[i];
        z.build(W);
        ZFunc z2;
        {
            string W2 = w[i] + "#" + s0;
            z2.build(W2);
        }
        int res = 0;
        range(j, (int) s0.size() + 1) {
            int start = -j + (int) s0.size() + 1;
            if (j == 0) start = 0;
            if (start > 1 && start - 1 < (int) w[i].size()) {
                if (z2.z[(int) W.size() - start + 1] != start - 1) {
                    continue;
                }
            }
            bool bad = false;
            w2 = "";
            for (int e = start; e < (int) w[i].size(); e += (int)s0.size() + 1) {
                int o = e + (int) s0.size() + 1;
                if (z.z[o] == s0.size()) continue;
                if (z.z[o] + o == W.size()) continue;
                bad = true;
                break;
            }
            if (bad) continue;
            for (int e = start; e <= (int) w[i].size(); e += (int)s0.size() + 1) {
                if (e != 0) {
                    w2 += w[i][e - 1];
                }
            }
            if (w2.empty()) {
                if (start != 0) {
                    int pos = (int) W.size() - start + 1;
                    if (z2.z[pos] != (int) w[i].size()) continue;
                }
                res = add(res, binpow(2, k[i]));
                continue;
            }
            while (K + 1 < k[i]) {
                if (K != -1) {
                    range(ae, 26) {
                        psum[ae][K + 1] = psum[ae][K];
                    }
                }
                K++;
                psum[t[K] - 'a'][K] = add(psum[t[K] - 'a'][K], rev(st2[K]));
            }
            answer = 0;
            solve(0, 1, 0);
            res = add(res, answer);
        }
        ans[i] = res;
    }
    range(i, q) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}