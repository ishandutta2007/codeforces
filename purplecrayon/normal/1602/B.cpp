#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
 
vector<int> get(const vector<int>& a) {
    int n = sz(a);
    vector<int> cnt(n + 1);
    for (auto c : a) cnt[c]++;
    vector<int> b = a;
    for (auto& c : b) c = cnt[c];
    return b;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    vector<vector<int>> ops; ops.push_back(a);
    for (int rep = 0; rep <= 2*n; rep++) {
        ops.push_back(get(ops.back()));
    }
    int q; cin >> q;
    while (q--) {
        int i; ll k; cin >> i >> k, --i;
        cout << ops[min<long long>(k, sz(ops)-1)][i] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}