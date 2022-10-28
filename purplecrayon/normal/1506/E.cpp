#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    int n; cin >> n;
    vector<int> q(n); for (auto& it : q) cin >> it, --it;

    vector<int> vis(n, n);
    for (int i = 0; i < n; i++) {
        vis[q[i]] = min(vis[q[i]], i);
    }
    set<int> s1, s2;
    for (int i = 0; i < n; i++) if (vis[i] == n) s1.insert(i), s2.insert(i);

    vector<int> ans1(n), ans2(n);
    for (int i = 0; i < n; i++) {
        if (vis[q[i]] == i) {
            ans1[i] = ans2[i] = q[i];
        } else {
            ans1[i] = *s1.begin(); s1.erase(s1.begin());
            ans2[i] = *prev(s2.upper_bound(q[i])); s2.erase(prev(s2.upper_bound(q[i])));
        }
    }
    for (auto& it : ans1) cout << it+1 << ' '; cout << '\n';
    for (auto& it : ans2) cout << it+1 << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}