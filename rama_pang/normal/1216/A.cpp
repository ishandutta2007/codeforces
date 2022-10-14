#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define db(v) cout << #v << " is " << v << endl
using namespace std;
using lint = long long;
using pii = pair<int, int>;
using pll = pair<lint, lint>;

int main() {
    int n; cin >> n;
    string ans; int anss = 0;
    for (int i = 1; i <= n / 2; i++) {
        char a, b; cin >> a >> b;
        if (a == 'a' && b == 'a') {
            ans.push_back('a');
            ans.push_back('b');
            anss++;
        }
        if (a == 'a' && b == 'b') {
            ans.push_back('a');
            ans.push_back('b');
        }
        if (a == 'b' && b == 'a') {
            ans.push_back('b');
            ans.push_back('a');
        }
        if (a == 'b' && b == 'b') {
            ans.push_back('a');
            ans.push_back('b');
            anss++;
        }
    }
    cout << anss << "\n";
    cout << ans << "\n";
}