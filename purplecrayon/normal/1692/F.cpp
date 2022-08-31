#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    int cnt[10]={};
    while (n--) {
        int x; cin >> x;
        cnt[x % 10]++;
    }
    for (int a = 0; a < 10; a++) for (int b = 0; b < 10; b++) for (int c = 0; c < 10; c++) {
        cnt[a]--, cnt[b]--, cnt[c]--;
        if (cnt[a] >= 0 && cnt[b] >= 0 && cnt[c] >= 0 && (a + b + c) % 10 == 3) {
            cout << "YES\n";
            return;
        }
        cnt[a]++, cnt[b]++, cnt[c]++;
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}