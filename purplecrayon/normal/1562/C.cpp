#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;

int n;
string s;

void solve(){
    cin >> n >> s;
    auto len = [&](int l, int r) -> bool {
        return (r-l+1) >= n/2;
    };
    for (int i = 0; i < n; i++) if (s[i] == '0') {
        if (i && len(0, i-1) && len(0, i)) {
            cout << 1 << ' ' << i+1 << ' ' << 1 << ' ' << i << '\n';
            return;
        }
        if (i < n-1 && len(i, n-1) && len(i+1, n-1)) {
            cout << i+1 << ' ' << n << ' ' << i+2 << ' ' << n << '\n';
            return;
        }
    }
    assert(*min_element(s.begin(), s.end()) == '1');
    cout << 1 << ' ' << n-1 << ' ' << 2 << ' ' << n << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}