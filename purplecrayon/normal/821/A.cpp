#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

int n, a[66][66];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (a[i][j] == 1) continue;

        bool bad = 1;
        for (int s = 0; s < n; s++) for (int t = 0; t < n; t++) {
            if (a[i][s] + a[t][j] == a[i][j]) bad = 0;
        }
        if (bad){ cout << "No\n"; return; }
    }
    cout << "Yes\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}