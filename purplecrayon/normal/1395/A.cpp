#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5+10, MAXM = 1e5+10, ALP = 26, INF = 1e9+10, MOD = 1e9+7;
const int hA[4] = {1, 0, -1, 0}, kA[4] = {1, 0, -1, 0};
// const ll INF = 1e18+10;

void solve(){
    ll r, g, b, w; cin >> r >> g >> b >> w;
    int ans = r%2 + g%2 + b%2 + w%2;
    if (ans <= 1) cout << "YES\n";
    else {
        int nm = min(r, min(g, b));
        if (!nm) cout << "NO\n";
        else {
            ans = (r-1)%2 + (g-1)%2  + (b-1)%2 + (w+1)%2;
            if (ans <= 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; cin >> t;
    while (t--) solve();
}