#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n, k;
int a[MAXN];

void solve(){
    cin >> n >> k;
    int g = 0;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] %= k, g = gcd(g, a[i]); 
    set<int> s;
    int c = g;
    while (!s.count(c)) {
        s.insert(c);
        c += g;
        c %= k;
    }
    cout << sz(s) << '\n';
    for (auto c : s) cout << c << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}