#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
vector<int> v;
int t[4 * N];

void build(int vv, int l, int r){
    if (l == r){
        t[vv] = v[l];
        return ;
    }
    int m = (l + r) / 2;
    build(2 * vv, l, m);
    build(2 * vv + 1, m + 1, r);
    t[vv] = min(t[vv * 2], t[vv * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    if (l > r) return 1e18;
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve(){
    int n;
    cin >> n;
    v.clear();
    vector<int> mx(n);
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.pb(a);
    }
    build(1, 0, n - 1);
    mx[n - 1] = v[n - 1];
    for (int i = n - 2; i > -1; i--){
        mx[i] = max(mx[i + 1], v[i]);
    }
    int r = n - 1;
    int now = 0;
    for (int i = 0; i < n; i++){
        now = max(now, v[i]);
        r = max(r, i + 2);
        while(i + 1 < r - 1 && mx[r - 1] <= now){
            r--;
        }
        if (now == mx[r] && now == get(1, 0, n - 1, i + 1, r - 1)){
            cout << "YES" << "\n";
            cout << i + 1 << " " << r - i - 1 << " " << n - r << "\n";
            return ;
        }
        if (r < n - 1) r++;
        if (now == mx[r] && now == get(1, 0, n - 1, i + 1, r - 1)){
            cout << "YES" << "\n";
            cout << i + 1 << " " << r - i - 1 << " " << n - r << "\n";
            return ;
        }
    }
    cout << "NO" << "\n";
}
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}