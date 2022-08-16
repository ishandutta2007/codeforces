#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

bool done(int i, int j) {
    cout << i << ' ' << j << endl;
    string s; cin >> s;
    return s == "Done";
}
void solve(){
    for (int rep = 0; rep < 2; rep++) {
        for (int i = 1; i <= 8; i++) {
            if (i&1) {
                for (int j = 1; j <= 8; j++) {
                    if (done(i, j)) return;
                }
            } else {
                for (int j = 8; j >= 1; j--) {
                    if (done(i, j)) return;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}