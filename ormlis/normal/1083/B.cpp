#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;

const ld INF = 1e20;
const ld EPS = 1e-9;
const int maxN = 4e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    int cur = 1;
    string s, t;
    cin >> s >> t;
    if (k == 1) {
        cout << n << '\n';
        return;
    }
    ll answer = 0;
    range(i, n) {
        if (cur == 1 && s[i] == t[i]) {
            answer++;
            continue;
        }
        if (cur == 1) {
            cur = 2;
            answer += cur;
            continue;
        }
        if (cur == k) {
            answer += cur;
            continue;
        }
        ll to = cur * 2 - 2;
        if (s[i] == 'a') {
            to++;
        }
        if (t[i] == 'b') to++;
        if (to >= k) {
            answer += k;
            cur = k;
            continue;
        }
        answer += to;
        cur = to;
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(30) << fixed;
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}