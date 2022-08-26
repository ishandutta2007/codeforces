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
const int maxN = 1e6 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int mt[maxN];
int used[maxN];
int T = 1;
vector<int> g[maxN];

bool dfs(int v) {
    if (used[v] == T) return false;
    used[v] = T;
    for(auto &u : g[v]) {
        if (mt[u] == -1 || dfs(mt[u])) {
            mt[u] = v;
            mt[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    int d, n; cin >> d >> n;
    vector<string> a(n);
    range(i, n) cin >> a[i];
    range(i, n * 2) mt[i] = -1;
    range(i, n) {
        range(j, n) {
            if (i == j) continue;
            bool b = false;
            range(w, d) {
                if (a[i][w] > a[j][w]) {
                    b = true;
                    break;
                }
            }
            if (b) continue;
            g[i].push_back(j + n);
        }
    }
    vector<int> cnt(n);
    range(i, n) range(j, d) cnt[i] += (a[i][j] == '1');
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int i, const int j) {
        return cnt[i] > cnt[j];
    });
    for(auto &i : ord) {
        if (mt[i] != -1) continue;
        T++;
        dfs(i);
    }
    vector<char> res;
    range(i, n) {
        if (mt[i + n] != -1) continue;
        int j = i;
        string cur = "";
        range(w, d) cur += '0';
        while(j >= 0) {
            range(w, d) {
                if (cur[w] < a[j][w]) {
                    res.push_back('0' + w);
                    cur[w] = '1';
                }
            }
            j = mt[j] - n;
        }
        res.push_back('R');
    }
    res.pop_back();
    cout << res.size() << '\n';
    for(auto &x : res) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}