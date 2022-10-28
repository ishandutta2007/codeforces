#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 60, ALP = 26, MAXL = 20, INF = 1e9+10;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, ps = 0;
    for (int i = 0; i < n; i++){
        ps += (s[i] == ')' ? -1 : 1);
        if (ps < 0) ans++, ps++;
    }
    cout << ans << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}