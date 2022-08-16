#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n*m); for (auto& c : a) cin >> c;
    vector<int> p(n*m); iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j){ 
        if (a[i] != a[j]) return a[i] < a[j];
        return i > j;
    });
    for (int i = 0; i < n*m; i++) {
        int j = i;
        while (j < n*m && a[p[j]] == a[p[i]]) j++;
        j--;

        if (i/m != j/m) {
            int right = j%m+1;
            int left = m-(i%m);
            int len = (j-i+1);
            //i...i+left-1 -> decreasing index (smallest numbers)
            //i+left...j -> decreasing (biggest numbers)
            reverse(p.begin()+i, p.begin()+i+len);

            reverse(p.begin()+i, p.begin()+i+left);
            reverse(p.begin()+i+left, p.begin()+(j-right+1));
            reverse(p.begin()+(j-right+1), p.begin()+i+len);
        }
        i = j;
    }


    vector<int> loc(n*m);
    for (int i = 0; i < n*m; i++) loc[p[i]] = i;

    vector<bool> bad(n*m);

    int ans = 0;
    for (int i = 0; i < n*m; i++) {
        int st = m*(loc[i]/m);
        for (int j = st; j <= loc[i]; j++) ans += bad[j];
        bad[loc[i]] = 1;
    }
    cout << ans << '\n';


    // if everybody of some type is in the same row, then just put them in reverse order of time arrival
    // put the earlier ones at the end
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}