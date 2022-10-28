#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e3+10, MOD = 1e9+7;
const int MAXM = 2e4+10;

int n, m;
int dist[MAXN], cnt[MAXN];

void solve() {
    cin >> n >> m;

    fill(dist, dist+n, MOD);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        cnt[a]++;
        if (b >= a) dist[a] = min(dist[a], b-a);
        else dist[a] = min(dist[a], n-a+b);
    }
    for (int s = 0; s < n; s++) {
        int cur = 0;
        for (int i = 0; i < n; i++) if (cnt[i]) {
            cur = max(cur, (s <= i ? i-s : n-s+i) + n*(cnt[i]-1) + dist[i]);
        }
        cout << cur << ' ';
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}