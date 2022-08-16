#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 1e9+7;

string get(string s, int k) {
    int n = sz(s);
    string one = s.substr(k-1, n-k+1); // n-k+1
    string two = s.substr(0, k-1);
    if (n % 2 == k % 2) reverse(two.begin(), two.end());
    return one + two;
}
void solve() {
    int n; string s; cin >> n >> s;

    pair<string, int> ans{string(n, 'z'), MOD};
    for (int k = 1; k <= n; k++) {
        ans = min(ans, make_pair(get(s, k), k));
    }
    cout << ans.first << '\n' << ans.second << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}