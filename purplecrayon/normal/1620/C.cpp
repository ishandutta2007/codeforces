#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

void solve() {
    int n, k; ll x; cin >> n >> k >> x, --x;
    string s; cin >> s;
    vector<int> v;
    for (int i = 0; i < n; i++) if (s[i] == '*') {
        int j = i;
        while (j < n && s[j] == '*') j++;
        j--;

        v.push_back(j - i + 1);
        i = j;
    }
    vector<int> cnt(sz(v));
    for (int i = sz(v)-1; i >= 0; i--) {
        int base = v[i] * k + 1;
        cnt[i] = x % base, x /= base;
    }

    int p = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            while (cnt[p]--) cout << 'b';
            p++;

            int j = i;
            while (j < n && s[j] == '*') j++;
            j--;

            v.push_back(j - i + 1);
            i = j;
        } else {
            cout << 'a';
        }
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}