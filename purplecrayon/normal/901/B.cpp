#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e2+10, MOD = 1e9+7;

int n;
vector<bool> a[MAXN];

void solve(){
    cin >> n;
    a[0] = {1}, a[1] = {0, 1};
    for (int i = 2; i <= n; i++) {
        a[i] = vector<bool>(i+1, 0);
        for (int j = 1; j <= i; j++)  a[i][j] = a[i][j]^a[i-1][j-1];
        for (int j = 0; j < i-1; j++) a[i][j] = a[i][j]^a[i-2][j];
    }
    cout << sz(a[n])-1 << '\n';
    for (auto c : a[n]) cout << c << ' '; cout << '\n';
    cout << sz(a[n-1])-1 << '\n';
    for (auto c : a[n-1]) cout << c << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}