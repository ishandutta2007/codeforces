#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& c : a) cin >> c;
    vector<int> b(n); for (auto& c : b) cin >> c;

    int M = min( *min_element(a.begin(), a.end()), *min_element(b.begin(), b.end()) );
    for (auto& c : a) c -= M;
    for (auto& c : b) c -= M;

    int N = max( *max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()) );

    vector<int> cnt_one(N + 2), cnt_two(N + 2);
    for (auto& c : a) cnt_one[c]++;
    for (auto& c : b) cnt_two[c]++;

    for (int i = 0; i <= N; i++) {
        if (cnt_two[i] < 0 || cnt_one[i] < cnt_two[i]) {
            cout << "NO\n";
            return;
        }
        cnt_one[i] -= cnt_two[i];
        cnt_two[i] = 0;

        cnt_two[i + 1] -= cnt_one[i];
    }
    for (auto& x : cnt_two) if (x) { 
        cout << "NO\n"; 
        return;
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}