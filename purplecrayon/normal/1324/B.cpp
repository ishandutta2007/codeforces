#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

const string yes = "YES\n", no = "NO\n";
void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    for (int i = 0; i < n; i++) for (int j = i+2; j < n; j++) if (a[i] == a[j]) { cout << yes; return; }
    cout << no;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}