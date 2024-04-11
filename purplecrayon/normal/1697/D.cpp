#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

string hidden = "abab";

char qry1(int c) {
    cout << "? 1 " << c+1 << endl;
#ifdef LOCAL
    return hidden[c];
#endif
#ifndef LOCAL
    char ans; cin >> ans;
    return ans;
#endif
}
int qry2(int l, int r) {
    cout << "? 2 " << l+1 << ' ' << r+1 << endl;
#ifdef LOCAL
    set<char> s;
    for (int i = l; i <= r; i++) s.insert(hidden[i]);
    return sz(s);
#endif

#ifndef LOCAL
    int ans; cin >> ans;
    return ans;
#endif
}
void solve() {
#ifdef LOCAL
    int n = sz(hidden);
#endif
#ifndef LOCAL
    int n; cin >> n;
#endif
    int tt = 0;
    vector<int> root(n);

    int last[26];
    memset(last, -1, sizeof(last));
    last[root[0] = tt++] = 0;

    for (int i = 1; i < n; i++) {
        vector<int> imp;
        for (int j = 0; j < 26; j++) if (last[j] != -1) imp.push_back(last[j]);

        sort(imp.begin(), imp.end());
        int lo = -1, hi = sz(imp), mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            if (qry2(imp[mid], i) == sz(imp) - mid) lo = mid;
            else hi = mid;
            mid = (lo + hi) / 2;
        }
        if (lo == -1) {
            last[root[i] = tt++] = i;
        } else {
            last[root[i] = root[imp[lo]]] = i;
        }
    }

    string ans(n, '?');
    for (int i = 0; i < tt; i++) {
        char c = qry1(last[i]);
        for (int j = 0; j < n; j++) if (root[j] == i) ans[j] = c;
    }
    cout << "! " << ans << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}