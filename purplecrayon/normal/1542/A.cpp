#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n; n *= 2;
    int cnt[2]={};
    while (n--) {
        int x; cin >> x;
        cnt[x&1]++;
    }
    cout << (cnt[0]==cnt[1] ? "Yes\n" : "No\n");
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}