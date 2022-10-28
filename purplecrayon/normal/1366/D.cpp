#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

const int MAXV = 1e7+10;
int pf[MAXV];

void pre(){ //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
}
vector<pair<int, int>> get_pf(int n){
    vector<pair<int, int>> r;

    int c=n;
    while (c > 1){
        int v = pf[c];
        r.emplace_back(v, 0);
		while (c%v == 0) r.back().second++, c /= v;
    }
    return r;
}

void solve(){
    pre();
    int n; cin >> n;
    vector<int> a(n, -1), b(n, -1);
    for (int rep = 0; rep < n; rep++) {
        int c; cin >> c;
        auto p = get_pf(c);
        if (sz(p) == 1) continue;

        a[rep] = p[0].first;
        int ans = 1;
        for (int j = 1; j < sz(p); j++) ans *= p[j].first;
        b[rep] = ans;
    }
    for (auto c : a) cout << c << ' '; cout << '\n';
    for (auto c : b) cout << c << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}