#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()

typedef vector<int> vi;
typedef long long ll;
const int MAXN = 3e5+10, MAXM = 3e5+10, MAXL = 21;
const string yes = "YES\n", no = "NO\n";

void solve(){
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll xd = x2-x1, yd = y2-y1;
    if (xd < 0 || yd < 0) { cout << "0\n"; return; }
    cout << xd*yd+1 << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}