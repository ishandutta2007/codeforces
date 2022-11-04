#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

#define sz(x) (int) (x).size()

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 1000;

int n, m, k;
int a[N];

void run() {
    cin >> n >> m >> k;
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        if (c == 0) continue;
        if (c <= k) ans = min(ans, abs(i - m) * 10);
    }
    cout << ans << "\n";
}