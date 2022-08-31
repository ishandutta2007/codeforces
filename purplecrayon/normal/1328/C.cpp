#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    string one, two;
    bool done = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> best{-1, -1};
        for (int a = 0; a < 3; a++) for (int b = 0; b < 3; b++) if ((a + b) % 3 == s[i] - '0') {
            if (i == 0 && (a == 0 || b == 0)) continue;
            if (done && (a < b)) continue;
            if (!done && (a > b)) continue;
            if (best == make_pair(-1, -1) || best > make_pair(b, a))
                best = make_pair(b, a);
        }
        one += best.second + '0';
        two += best.first + '0';
        if (best.first != best.second) done = 1;
    }
    cout << one << '\n' << two << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}