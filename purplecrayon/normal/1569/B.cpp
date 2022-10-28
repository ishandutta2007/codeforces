#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 15, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> two;
    for (int i = 0; i < n; i++) if (s[i] == '2') two.push_back(i);

    if (sz(two) == 1 || sz(two) == 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    vector<string> g(n, string(n, '='));
    for (int i = 0; i < sz(two); i++) {
        int j = (i+1)%sz(two);
        g[two[i]][two[j]] = '+';
        g[two[j]][two[i]] = '-';
    }
    for (int i = 0; i < n; i++) g[i][i] = 'X';
    for (auto& r : g) cout << r << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}