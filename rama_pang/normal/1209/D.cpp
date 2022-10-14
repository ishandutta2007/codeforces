#include <bits/stdc++.h>
#define fi first
#define se second
#define db(x) cout << #x << " is " << x << "\n"
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, K, p[200005];
int par(int n) {
    if (p[n] == n) return n;
    return p[n] = par(p[n]);
}
int main() {
    IOS;
    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        p[i] = i;
    }
    int ans = 0;
    for (int i = 0; i < K; i++) {
        int u, v; cin >> u >> v;
        int p1 = par(u);
        int p2 = par(v);
        if (p1 != p2) {
            p[p1] = p2;
        } else {
            ans++;
        }
    }
    cout << ans << "\n";
}