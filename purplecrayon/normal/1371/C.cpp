#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 110, ALP = 26, MAXL = 20, INF = 1e9+10;

void solve(){
    ll a, b, n, m; cin >> a >> b >> n >> m; 
    if (a > b) swap(a, b);
    if (a < m) { cout << "NO\n"; return; }
    a -= m;
    if (a+b < n) { cout << "NO\n"; return; }
    cout << "YES\n";
}
int main(){
    int t=0; cin >> t;
    while (t--) solve();
}