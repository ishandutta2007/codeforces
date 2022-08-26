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
#include <assert.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e7;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int bp(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, bp(a, b - 1));
    int m = bp(a, b/2);
    return mul(m, m);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> prefk(n+1,0), sufk(n+1,0), prefa(n+1,0), sufc(n+1,0);
    if (s[0] == 'a') prefa[0] = 1;
    if (s[0] == '?') prefk[0] = 1;
    if (s[n-1] == '?') sufk[n-1] = 1;
    if (s[n-1] == 'c') sufc[n-1] = 1;
    for(int i = 1; i < n; ++i) {
        prefa[i] = prefa[i-1];
        prefk[i] = prefk[i-1];
        if (s[i] == '?') prefk[i]++;
        if (s[i] == 'a') prefa[i]++;
    }
    for(int i = n - 2; i >= 0; --i) {
        sufc[i] = sufc[i+1];
        sufk[i] = sufk[i+1];
        if (s[i] == '?') sufk[i]++;
        if (s[i] == 'c') sufc[i]++;
    }
    int ans = 0;
    for(int i = 1; i <= n - 2; ++i) {
        if (s[i] != '?' && s[i] != 'b') continue;
        int ansleft = mul(prefa[i-1], bp(3, prefk[i-1]));
        if (prefk[i-1] > 0) ansleft = add(ansleft, mul(prefk[i-1], bp(3, prefk[i-1]-1)));
        int ansright = mul(sufc[i+1], bp(3, sufk[i+1]));
        if (sufk[i+1] > 0) ansright = add(ansright, mul(sufk[i+1], bp(3, sufk[i+1]-1)));
        ans = add(ans, mul(ansright, ansleft));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}