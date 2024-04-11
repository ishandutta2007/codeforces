#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 2e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int h, m; cin >> h >> m;
    string foo; cin >> foo;
    int a = (foo[0] - '0') * 10 + (foo[1] - '0');
    int b = (foo[3] - '0') * 10 + (foo[4] - '0');
    while(true) {
        ar<int, 4> tm = {a / 10, a % 10, b / 10, b % 10};
        bool bad = false;
        range(j, 4) {
            if (tm[j] == 0 || tm[j] == 1 || tm[j] == 8) continue;
            if (tm[j] == 5) {
                tm[j] = 2;
            } else if (tm[j] == 2){
                tm[j] = 5;
            } else {
                bad = true;
                break;
            }
        }
        if (!bad) {
            int x = tm[3] * 10 + tm[2];
            int y = tm[1] * 10 + tm[0];
            if (x < h && y < m) {
                string w = to_string(a);
                if (w.size() == 1) w = "0" + w;
                string t = to_string(b);
                if (t.size() == 1) t = "0" + t;
                cout << w << ":" << t << '\n';
                return;
            }
        }
        b++;
        if (b == m) {
            b = 0;
            a++;
        }
        if (a == h) {
            a = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}