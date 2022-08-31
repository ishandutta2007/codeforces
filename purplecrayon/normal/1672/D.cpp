#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x, --x;
    for (auto& x : b) cin >> x, --x;

    if (a.back() != b.back()) {
        cout << "NO\n";
        return;
    }

    vector<int> cnt(n);
    int j = 0;
    bool match = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[j]) {
            bool can = j < n-1 && a[i] == b[j];
            if (match && b[j-1] == b[j]) can = true;
            if (can && cnt[b[j]]) cnt[b[j]]--, j++, i--;
            else cnt[a[i]]++, match = false;
        } else {
            match = true;
            j++;
        }
    }
    cnt[a.back()] = 0;
    if (*std::max_element(cnt.begin(), cnt.end())) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}