//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const LL INF = 1e12;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = sz(s);
    LL open[n];
    LL ans = 0;
    int diff = 0;
    string t = s;
    set<pll> nums;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            open[i] = -INF;
            ans += INF;
        }
        else if (s[i] == ')')
            open[i] = INF;
        else {
            LL x, y;
            cin >> x >> y;
            ans += y;
            open[i] = x - y;
            s[i] = ')';
        }
        t[i] = ')';
        diff--;
        nums.insert(MP(open[i], i));
        if (diff < 0) {
            auto chz = *nums.begin();
            nums.erase(nums.begin());
            t[chz.R] = '(';
            ans += chz.L;
            diff += 2;
        }
    }
    if (ans > INF)
        return cout << -1 << '\n', 0;
    cout << ans << '\n';
    cout << t << '\n';
    return 0;
}