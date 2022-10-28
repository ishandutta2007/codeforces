#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

void solve(){
    int a, b; cin >> a >> b;

    vector<int> ans;
    for (int i = 0; i <= a+b; i++) { //i wins for server
        bool bad = 1;

        int p1 = (a+b)/2, p2 = (a+b+1)/2;
        for (int rep : {0, 1}) {
            int x = (i+a-p2)/2;
            if (x > p1 || i-x > p2 || x < 0 || x > a || i-x > b || i < x);
            else {
                if (x + p2-(i-x) == a && (p1-x) + (i-x) == b) {
                    bad = 0;
                }
            }
            swap(p1, p2);
        }
        if (!bad) ans.push_back(a+b-i);
    }
    reverse(ans.begin(), ans.end());

    cout << sz(ans) << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}