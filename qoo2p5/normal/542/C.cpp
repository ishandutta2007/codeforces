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

const int N = 202;

int n;
int f[N];
bool c[N];
bool vis[N];

ll lcm(ll x, ll y) {
    return x / __gcd(x, y) * y;
}

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }
    
    int max_h = 0;
    ll ans = 1;
    
    for (int i = 0; i < n; i++) {        
        bool ok = true;
        int v = i;
        vis[v] = 1;
        while (1) {
            if (c[f[v]]) {
                ok = false;
                break;
            }
            if (vis[f[v]]) {
                break;
            }
            
            v = f[v];
            vis[v] = 1;
        }
        
        if (ok) {
            int len = 1;
            int u = f[v];
            c[u] = 1;
            while (u != v) {
                u = f[u];
                c[u] = 1;
                len++;
            }
            ans = lcm(ans, len);
        }
        
        fill(vis, vis + n, 0);
    }
    
    for (int i = 0; i < n; i++) {
        if (c[i]) continue;
        
        int depth = 0;
        int v = i;
        while (!c[v]) {
            depth++;
            v = f[v];
        }
        
        max_h = max(max_h, depth);
    }
    
    assert(ans > 0);
    ll q = ans;
    while (q < max_h) {
        q += ans;
    }
    
    cout << q << "\n";
}