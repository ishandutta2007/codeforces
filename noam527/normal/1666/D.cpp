#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string s, t;

void solve(){
    cin >> s >> t;
    int seen[256] = {};
    int n = s.size(), m = t.size();
    int nxt = m - 1;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == t[nxt]){
            if (seen[s[i]]){
                cout << "NO\n";
                return;
            }
            nxt--;
            if (nxt == -1) break;
        }
        else {
            seen[s[i]] = 1;
        }
    }
    if (nxt == -1) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while (t--) solve();
}