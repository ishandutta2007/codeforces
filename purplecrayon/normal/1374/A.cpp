#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 5e5+10, ALP = 26, MAXL = 20, INF = 1e9+10;

void solve(){
    ll x, y, n; cin >> x >> y >> n;
    ll r = n%x;
    cout << n-((r-y+x)%x) << "\n";
}
int main(){
    int t; cin >> t;
    while (t--) solve();
}