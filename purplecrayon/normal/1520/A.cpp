#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) if (s[i] == s[j]) {
            for (int k = i+1; k < j; k++) if (s[k] != s[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}