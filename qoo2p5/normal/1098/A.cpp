#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);
const ll MOD = (ll) (1e9 + 7);

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = (int) 1e5 + 123;

int n, p[N], h[N];
ll s[N], a[N];
ll ans;
int deg[N];
vector<int> g[N];

void run() {
    cin >> n;
    h[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        h[i] = h[p[i]] + 1;
        deg[p[i]]++;
        g[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    a[1] = s[1];
    for (int i = 2; i <= n; i++) {
        if (s[i] == -1) {
            s[i] = s[p[i]];
            a[i] = LINF;
            for (int to : g[i]) {
                a[i] = min(a[i], s[to] - s[i]);
            }
            if (deg[i] == 0) {
                a[i] = 0;
            }
            s[i] += a[i];
        } else {
            a[i] = s[i] - s[p[i]];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i];
        if (a[i] < 0) {
            cout << "-1\n";
            return;
        }
    }
    cout << ans << "\n";
}