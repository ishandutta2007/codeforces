#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 4e5+10, MOD = 1e9+7; 

void pr(vector<int> a) {
    int n = sz(a);
    for (int i = 0; i < n; i++) {
        cout << (a[i] == +1 ? '(' : ')');
    }
    cout << '\n';
}
bool bad(vector<int> a) {
    int ps = 0, n = sz(a);
    for (int i = 0; i < n; i++) {
        ps += a[i];
        if (ps < 0) return 1;
    }
    return ps;
}
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n), b(n);
    bool turn = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') a[i] = b[i] = +1;
        else {
            if (turn) a[i] = +1, b[i] = -1;
            else a[i] = -1, b[i] = +1;
            turn ^= 1;
        }
    }
    int bal_a = 0, bal_b = 0;
    for (int i = 0; i < n; i++) bal_a += a[i], bal_b += b[i];
    if (bal_a != bal_b || bal_a < 0 || bal_b < 0 || (bal_a&1) || (bal_b&1)){ cout << "NO\n"; return; }
    for (int i = n-1; i >= 0; i--) if (s[i] == '1' && bal_a && bal_b) {
        a[i] = -1, b[i] = -1;
        bal_a -= 2, bal_b -= 2;
    }
    if (bad(a) || bad(b)) cout << "NO\n";
    else {
        cout << "YES\n";
        pr(a), pr(b);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}