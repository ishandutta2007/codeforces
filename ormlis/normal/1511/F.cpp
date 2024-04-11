#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>
#include <list>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 3e5 + 100;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

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

void add2(int &a, int b) {
    a = add(a, b);
}

int dp[500][8][6];

using matrix = vector<vector<int>>;

matrix mul(const matrix &a, const matrix &b) {
    matrix c(a.size(), vector<int> (b[0].size()));
    range(i, (int)a.size()) {
        range(j, (int)b[0].size()) {
            range(r, (int)b.size()) {
                add2(c[i][j], mul(a[i][r], b[r][j]));
            }
        }
    }
    return c;
}

matrix binpow(const matrix &a, int b) {
    if (b == 1) return a;
    if (b % 2) return mul(a, binpow(a, b - 1));
    auto m = binpow(a, b / 2);
    return mul(m, m);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    range(i, n) cin >> a[i];
    const int K = 6 * 8 * 6;
    vector<vector<int>> dpm(K, vector<int> (K));
    auto getH = [&] (int i, int j, int e) {
        return i * 8 * 6 + j * 6 + e;
    };
    dp[0][0][0] = 1;
    vector<vector<int>> kekw(K, vector<int> (K));
    vector<int> ord;
    for (int len = 0; len < 6; ++len) {
            range(li, n) {
                for (int emp = 5; emp >= 0; --emp) {
                    if (len) {
                        dpm[getH(len, li, emp)][getH(len - 1, li, emp)]++;
                    }
                    if (emp > a[li].size()) continue;
                    //if (dp[t][len][li][emp] == 0) continue;
                    //cout << t << ' ' << len << ' ' << li << ' ' << emp << '\n';
                    range(i, n) {
                        bool b = false;
                        range(j, min(emp, (int) a[i].size())) {
                            if (a[i][j] != a[li][(int) a[li].size() - emp + j]) {
                                b = true;
                            }
                        }
                        if (b) continue;
                        if (a[i].size() <= emp) {
                            if (len != 5) continue;
                            kekw[getH(len, li, emp - (int) a[i].size())][getH(len, li, emp)]++;
                            //add2(dp[len][li][emp - (int) a[i].size()], dp[len][li][emp]);
                        } else {
                            if (len + (int)a[i].size() - emp != 6) continue;
                            dpm[getH(len, li, emp)][getH(5, i, (int)a[i].size() - emp)]++;
                            //add2(dp[len + (int) a[i].size() - emp][i][(int) a[i].size() -emp], dp[len][li][emp]);
                        }
                    }
                }
            }
    }
    for(int emp = 5; emp >= 0; --emp) {
        range(i, n) {
            ord.push_back(getH(5, i, emp));
        }
    }
    vector<bool> used(K);
    function<void(int)> go = [&] (int x) {
        if (used[x]) return;
        used[x] = true;
        range(j, K) {
            if (dpm[x][j]) go(j);
        }
    };

    for(auto &h1 : ord) {
        range(h2, K) {
            if (!kekw[h1][h2]) continue;
            range(j, K) {
                add2(dpm[j][h1], mul(kekw[h1][h2], dpm[j][h2]));
            }
        }
    }
    go(getH(5, 0, 0));
    vector<int> kek2;
    range(i, K) {
        if (used[i]) kek2.push_back(i);
    }
    auto get_ind = [&] (int x) {
        int j = lower_bound(all(kek2), x) - kek2.begin();
        if (j == kek2.size() || (kek2[j] != x)) return -1;
        return j;
    };
    int K2 = kek2.size();
    vector<vector<int>> dpm2(K2, vector<int> (K2));
    range(i, K2) {
        range(j, K2) {
            dpm2[i][j] = dpm[kek2[i]][kek2[j]];
        }
    }
    assert(K2 < K);
    vector<vector<int>> cur(1, vector<int> (K2));
    cur[0][get_ind(getH(5, 0, 0))] = 1;
    cur = mul(cur, binpow(dpm2, m));
    int answer = 0;
    range(li, n) add2(answer, cur[0][get_ind(getH(5, li, 0))]);
    cout << answer;
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