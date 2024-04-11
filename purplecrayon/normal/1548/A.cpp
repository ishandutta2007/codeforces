#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n, m, cnt_big = 0;
int big[MAXN];

void solve(){
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b, --a, --b;
        if (a > b) swap(a, b);
        if (!big[a]) cnt_big++;
        big[a]++;
    }
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b, --a, --b;
            if (a > b) swap(a, b);
            if (!big[a]) cnt_big++;
            big[a]++;
        }
        if (t == 2) {
            int a, b; cin >> a >> b, --a, --b;
            if (a > b) swap(a, b);
            big[a]--;
            if (!big[a]) cnt_big--;
        }
        if (t == 3) {
            cout << n-cnt_big << '\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}