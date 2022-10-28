#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    if (n < 1e3){ cout << "Petr\n"; return; }

    int touch = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a, --a;
        touch += int(i == a); //untouched
    }
    const int MAGIC = 3;
    if (touch >= MAGIC) cout << "Petr\n";
    else cout << "Um_nik\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}