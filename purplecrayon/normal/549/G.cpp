#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, a[MAXN];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] += i;
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        a[i] -= i;
        if (i && a[i] < a[i-1]) {
            cout << ":(\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}