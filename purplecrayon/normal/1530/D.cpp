#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c, --c;
    vector<bool> used(n); for (auto c : a) used[c] = 1;
    vector<int> un; for (int i = 0; i < n; i++) if (!used[i]) un.push_back(i);

    vector<int> ans(n, -1);
    vector<bool> given(n);
    for (auto c : un) {
        if (!given[a[c]]) {
            ans[c] = a[c];
            given[a[c]] = 1;
        }
    }
    for (int i = 0; i < n; i++) if (!given[a[i]]) {
        ans[i] = a[i];
        given[a[i]] = 1;
    }

    vector<int> left; for (int i = 0; i < n; i++) if (ans[i] == -1) left.push_back(i);
    //left indices, left numbers

    vector<int> loc_left(n, -1);
    for (int i = 0; i < sz(left); i++) loc_left[left[i]] = i;

    assert(sz(un) == sz(left));
    for (int i = 0; i < sz(un); i++) {
        if (loc_left[un[i]] != -1) {
            swap(un[i], un[loc_left[un[i]]]);
        }
    }

    for (int i = 0; i < sz(left); i++) {
        ans[left[i]] = un[(i+1)%sz(left)];
    }

    int tot = 0;
    for (int i = 0; i < n; i++) if (ans[i] == a[i]) { tot++; assert(ans[i] != i); }
    assert(tot == n-sz(un));

    cout << tot << '\n';
    for (auto c : ans) cout << c+1 << ' '; cout << '\n';

    //unused stuff -> numbers that don't exist in the array
    //if there are >= 2, cyclic shift
    //els
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}