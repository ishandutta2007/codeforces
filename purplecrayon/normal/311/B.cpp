#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()

typedef vector<int> vi;
typedef long long ll;
const int MAXN = 1e5+10, MAXM = 3e5+10, MAXL = 21, LEN = 320;
const string yes = "YES\n", no = "NO\n";
const ll INF = 1e18+10;

int n, m, p;
ll d[MAXN], a[MAXN], cur[MAXN], pre[MAXN], ps[MAXN];

ll cost(int k, int j){ return a[j]*(j-k+1)-(ps[j]-(k?ps[k-1]:0)); }

void compute(int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l+r)>>1;
    pair<ll, int> best = {INF, -1};
    for (int k = optl; k <= min(mid, optr); k++){
        best = min(best, {(k?pre[k-1]:0)+cost(k, mid), k});
    }
    cur[mid] = best.first;
    int opt = best.second;
    compute(l, mid - 1, optl, opt), compute(mid + 1, r, opt, optr);
}
void solve(){
    cin >> n >> m >> p;
    d[0] = 0; for (int i = 1; i < n; i++) cin >> d[i], d[i] += d[i-1];
    for (int i = 0; i < m; i++) {
        ll h, t; cin >> h >> t, --h;
        a[i] = t-d[h], pre[i] = INF;
    }
    // for (int i = 0; i < m; i++) cout << a[i] << " ";
    // cout << "\n";
    sort(a, a+m);
    for (int i = 0; i < m; i++) ps[i] = (i?ps[i-1]:0)+a[i];
    // for (int i = 0; i < n; i++) cout << d[i] << " ";
    // cout << "\n";
    for (int i = 0; i < p; i++){
        compute(0, m-1, 0, m-1);
        for (int j = 0; j < m; j++) pre[j] = cur[j];
    }
    cout << pre[m-1];
}
int main(){
    ios::sync_with_stdio(false); cin.sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}