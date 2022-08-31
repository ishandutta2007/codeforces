#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    string s, t; cin >> s >> t;
    if (t == "abc") {
        sort(s.begin(), s.end(), [&](char a, char b){
            if (a == 'b' && b == 'c' || a == 'c' && b == 'b') return a > b;
            return a < b;
        });
        if (s[0] != 'a') sort(s.begin(), s.end());
        cout << s << '\n';
    } else {
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}