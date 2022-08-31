#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

const int MAXV = 3e6+10;
int pf[MAXV], cnt[MAXV];

void pre() {
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j += i) if (pf[j] == -1) pf[j] = i;
    }
    int ans = 1;
    memset(cnt, -1, sizeof(cnt));
    for (int i = 2; i < MAXV; i++) if (pf[i] == i) cnt[i] = ans++;
}

void solve() {
    pre();

    int n; cin >> n;
    multiset<int> b;
    for (int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        b.insert(x);
    }

    vector<int> ans;
    while (sz(b)) {
        int x = *b.rbegin(); b.erase(prev(b.end()));
        if (pf[x] == x) { // prime
            ans.push_back(cnt[x]);
            b.erase(b.find(cnt[x]));
        } else {
            ans.push_back(x);
            b.erase(b.find(x / pf[x]));
        }
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}