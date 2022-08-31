#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e3+10, MOD = 998244353;

pair<int, int> get(string s) {
    int n = sz(s);
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    
    pair<int, int> ans{0, 0};
    for (int i = 0; i < n; i++) {
        int l = i - d1[i] + 1;
        int r = i + d1[i] - 1;
        if (l == 0) ans.first = max(ans.first, r - l + 1);
        if (r == n-1) ans.second = max(ans.second, r - l + 1);
    }
    for (int i = 0; i < n; i++) {
        int l = i - d2[i];
        int r = i + d2[i] - 1;
        if (l == 0) ans.first = max(ans.first, r - l + 1);
        if (r == n-1) ans.second = max(ans.second, r - l + 1);
    }
    return ans;
}
void solve() {
    string s; cin >> s;
    int n = sz(s);
    int cnt = 0;
    for (int l = 0, r = n-1; l < r; l++, r--) {
        if (s[l] != s[r]) break;
        cnt++;
    }
    if (2*cnt >= n - 1) { // palindrome
        cout << s << '\n';
        return;
    }
    string t(s.begin() + cnt, s.end() - cnt);
    auto [one, two] = get(t);
    if (one > two) {
        for (int i = 0; i < cnt; i++) cout << s[i];
        for (int i = cnt; i < cnt + one; i++) cout << s[i];
        for (int i = n - cnt; i < n; i++) cout << s[i];
        cout << '\n';
    } else {
        for (int i = 0; i < cnt; i++) cout << s[i];
        for (int i = n - cnt - two; i < n - cnt; i++) cout << s[i];
        for (int i = n - cnt; i < n; i++) cout << s[i];
        cout << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}