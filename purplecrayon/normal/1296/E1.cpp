#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, ans[MAXN];
int last[2];
string s;

void solve() {
    cin >> n >> s;
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; i++) {
        int m = (last[0] < last[1] ? 0 : 1);
        int me = s[i] - 'a';
        if (me >= last[m^1]) last[m^1] = me, ans[i] = m^1;
        else if (me >= last[m]) last[m] = me, ans[i] = m;
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}