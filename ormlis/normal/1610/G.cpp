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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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
const int maxN = 1e5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = 2;

const int mods[4] = {998244353, (int) 1e9 + 7, (int) 1e9 + 9, (int) 1e9 + 123};

struct ModNum {
    ar<int, K> num{};

    ModNum() {
        rep(i, K) num[i] = 0;
    }

    ModNum(int x, int y) {
        num[0] = x;
        num[1] = y;
    }
};

ModNum P;

void gen() {
    rep(i, K) {
        P.num[i] = 0;
        while (P.num[i] < 1000) P.num[i] = rng() % mods[i];
    }
}

bool operator!=(const ModNum &a, const ModNum &b) {
    return a.num != b.num;
}

bool operator==(const ModNum &a, const ModNum &b) {
    return a.num == b.num;
}

bool operator<(const ModNum &a, const ModNum &b) {
    return a.num < b.num;
}

ModNum add(ModNum a, ModNum b) {
    rep(i, K) {
        a.num[i] += b.num[i];
        if (a.num[i] >= mods[i]) a.num[i] -= mods[i];
    }
    return a;
}

ModNum sub(ModNum a, ModNum b) {
    rep(i, K) {
        a.num[i] -= b.num[i];
        if (a.num[i] < 0) a.num[i] += mods[i];
    }
    return a;
}

ModNum mul(ModNum a, ModNum b) {
    rep(i, K) {
        a.num[i] = (1ll * a.num[i] * b.num[i]) % mods[i];
    }
    return a;
}


void solve() {
    gen();
    string s;
    cin >> s;
    int n = s.size();
    const int LG = 20;
    vvi up(n + 1, vi(LG, -1));
    vector<vector<ModNum>> hup(n + 1, vector<ModNum>(LG, {-1, -1}));
    vi pref(n + 1);
    rep(i, n) {
        pref[i + 1] = pref[i];
        if (s[i] == '(') pref[i + 1]++;
        else pref[i + 1]--;
    }
    vector<ModNum> stP(LG + 1);
    stP[0] = P;
    for (int i = 1; i <= LG; ++i) stP[i] = mul(stP[i - 1], stP[i - 1]);
    vector<int> stk = {n};
    vector<int> stk2 = {n};
    auto comp = [&](int i, int j) {
        for (int e = LG - 1; e >= 0; --e) {
            if (up[i][e] == -1 || up[j][e] == -1) continue;
            if (hup[i][e] == hup[j][e]) {
                i = up[i][e];
                j = up[j][e];
            }
        }
        if (hup[i][0].num == hup[j][0].num) {
            i = up[i][0];
            j = up[j][0];
            if (i == j || i == -1) return true;
            return false;
        }
        return hup[i][0].num[0] > hup[j][0].num[0];
    };
    int mn = pref[n];
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && pref[stk.back()] >= pref[i]) stk.pop_back();
        while (!stk2.empty() && pref[stk2.back()] < pref[i]) {
            stk2.pop_back();
        }
        int r = -1;
        if (stk.empty()) {
            r = n + 1;
        } else {
            r = stk.back();
        }
        int to = -1;
        {
            int l1 = -1, r1 = stk2.size();
            while (r1 - l1 > 1) {
                int mid = (r1 + l1) / 2;
                if (stk2[mid] >= r) {
                    l1 = mid;
                } else {
                    r1 = mid;
                }
            }
            to = r1;
        }
        if (to == (int) stk2.size()) {
            assert(pref[i + 1] - pref[i] == -1);
            up[i][0] = i + 1;
            hup[i][0] = {1, 1};
        } else {
            assert(pref[stk2[to]] > pref[i]);
            up[i][0] = stk2[to];
            assert(up[i][0] == n || s[up[i][0]] == ')');
            hup[i][0] = {pref[stk2[to]] - pref[i] + 2, pref[stk2[to]] - pref[i] + 2};
        }
        mn = min(mn, pref[i]);
        if (mn == pref[i]) {
            up[i][0] = n;
            hup[i][0] = {pref[n] - pref[i] + 2, pref[n] - pref[i] + 2};
        }
        for (int j = 1; j < LG; ++j) {
            up[i][j] = up[up[i][j - 1]][j - 1];
            if (up[i][j] == -1) break;
            hup[i][j] = add(hup[i][j - 1], mul(stP[j - 1], hup[up[i][j - 1]][j - 1]));
        }
        stk.push_back(i);
        while (!stk2.empty() && pref[stk2.back()] == pref[i]) {
            if (comp(i, stk2.back())) {
                stk2.pop_back();
            } else {
                break;
            }
        }
        stk2.push_back(i);
    }
    int i = 0;
    string t;
    while (i != n) {
        if (hup[i][0].num[0] == 1) {
            t += ')';
        } else {
            rep(_, hup[i][0].num[0] - 2) {
                t += '(';
            }
        }
        i = up[i][0];
    }
    cout << t << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}