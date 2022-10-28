#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, q;
string s;

void solve() {
    cin >> n >> q >> s;

    auto bad = [&](int i) -> bool {
        if (i <= 0 || i >= n-1) return 0;
        return s[i-1] == 'a' && s[i] == 'b' && s[i+1] == 'c';
    };

    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += bad(i);

    while (q--) {
        int pos; char c; cin >> pos >> c, --pos;
        for (int i = pos-1; i <= pos+1; i++) cnt -= bad(i);
        s[pos] = c;
        for (int i = pos-1; i <= pos+1; i++) cnt += bad(i);
        cout << cnt << '\n';
    }

}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}