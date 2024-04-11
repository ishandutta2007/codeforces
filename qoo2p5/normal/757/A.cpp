#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

void run() {
    string s;
    cin >> s;
    map<char, int> cnt;
    
    // Bulbasaur. B, u * 2, l, b, a * 2, s, r
    for (char c : s) {
        cnt[c]++;
    }
    
    int ans = INF;
    ans = min(ans, cnt['B']);
    ans = min(ans, cnt['u'] / 2);
    ans = min(ans, cnt['l']);
    ans = min(ans, cnt['b']);
    ans = min(ans, cnt['a'] / 2);
    ans = min(ans, cnt['s']);
    ans = min(ans, cnt['r']);
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}