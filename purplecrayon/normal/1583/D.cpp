#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

int qry(vector<int> a) {
    cout << "?";
    for (int x : a) cout << ' ' << x;
    cout << endl;
    int x; cin >> x;
    return x;
}
void solve() {
    int n; cin >> n;
    vector<int> loc(n, -1);
    for (int i = 0; i < n; i++) {
        vector<int> a(n, 1);
        a[i] = 2;

        int x = qry(a); --x;
        if (x != i && x != -1) loc[i] = x;
    }
    for (int i = 0; i < n; i++) {
        vector<int> a(n, 2);
        a[i] = 1;

        int x = qry(a); --x;
        if (x != i && x != -1) loc[x] = i;
    }

    vector<int> ans(n, -1), rloc(n);
    int c = -1;
    for (int i = 0; i < n; i++) {
        if (loc[i] == -1) c = i;
        else rloc[loc[i]] = i;
    }
    for (int i = n; i >= 1; i--, c = rloc[c]) {
        ans[c] = i;
    }
    cout << '!';
    for (int x : ans) cout << ' ' << x;
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}


// 1 2 1 1 1 1 1 1 1 1
// find location of a[i]+1