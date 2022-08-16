#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int one = max_element(a.begin(), a.end()) - a.begin();
    int two = min_element(a.begin(), a.end()) - a.begin();
    cout << one+1 << ' ' << two+1 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}