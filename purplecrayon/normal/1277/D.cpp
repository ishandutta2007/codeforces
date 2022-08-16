#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    set<string> s;
    bool need[2] = {};
    int cnt[2] = {};
    vector<int> type(n, -1);
    vector<string> store(n);
    for (int i = 0; i < n; i++) {
        string a; cin >> a;
        store[i] = a;
        string b = a; reverse(b.begin(), b.end());
        if (s.count(b)) {
            s.erase(b);
        } else {
            s.insert(a);
        }
        if (a[0] == a.back()) need[a[0] - '0'] = 1;
        else {
            cnt[a[0] - '0']++;
            type[i] = a[0] - '0';
        }
    }
    if ((need[0] && need[1]) && (!cnt[0] && !cnt[1])) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    int change[2] = {};
    while (cnt[0] > cnt[1] + 1) change[0]++, cnt[0]--, cnt[1]++;
    while (cnt[1] > cnt[0] + 1) change[1]++, cnt[1]--, cnt[0]++;
    ans = change[0] + change[1];

    cout << ans << '\n';
    for (int i = 0; i < n; i++) if (type[i] != -1 && s.count(store[i])) {
        if (change[type[i]]) {
            cout << i+1 << ' ';
            change[type[i]]--;
        }
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}