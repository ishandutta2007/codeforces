#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e5+10, MOD = 1e9+7; 

void solve(){
    string s; cin >> s;
    int n = sz(s);
    int bad = -1;
    for (int i = 0; i < n; i++) if (s[i] != 'a') bad = i;
    if (bad == -1){ cout << "NO\n"; return; }
    cout << "YES\n";
    for (int i = 0; i <= n; i++) {
        //put the current letter right before position i
        int j = n-i;
        if (j != i && s[j-(j > i)] != 'a') {
            for (int k = 0; k < i; k++) cout << s[k];
            cout << 'a';
            for (int k = i; k < n; k++) cout << s[k];
            cout << '\n';
            return;
        }
    }
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}