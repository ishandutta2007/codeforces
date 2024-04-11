#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool bad[26]; fill(bad, bad+26, 1);
    for (int i = 0; i < k; i++) { char c; cin >> c; bad[c-'a'] = 0; }
    
    ll ans=0, run=0;
    for (int i = 0; i < n; i++) {
        if (!bad[s[i]-'a']) {
            run++;
        } else {
            run = 0;
        }
        ans += run;
    }
    cout << ans << '\n';
}