#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9;
const ll LINF = (ll) 1e18 + 1;
const ld EPS = 1e-9;

const int N = (int) 1e5 + 123;

int n, m;
int a[N];

void run() {
    cin >> n >> m;
    int ans = INF;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        ans = min(ans, y - x + 1);
    }
    
    cout << ans << "\n";
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cout << cur << " ";
        cur++;
        if (cur == ans) {
            cur = 0;
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}