#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    LL x, y;
    cin >> s
        >> x >> y;
    if (x > y) {
        swap(x, y);
        reverse(all(s));
    }
    string t = s;
    for (int i = 0; i < sz(s); i++) {
        if (t[i] == '?')
            t[i] = '1';
    }
    int rone[sz(s) + 1] = {0};
    int lone[sz(s) + 1] = {0};
    LL cur = 0;
    for (int i = sz(s) - 1; i >= 0; i--) {
        rone[i] = rone[i + 1] + (t[i] == '1');
        if (t[i] == '1')
            cur += y * (sz(s) - i - rone[i]);
        else
            cur += x * rone[i];
    }
    LL ans = cur;
    for (int i = 0; i < sz(t); i++) {
        if (s[i] == '?') {
            lone[i + 1] = lone[i];
            cur -= (sz(s) - i - rone[i]) * y;
            cur -= (i - lone[i]) * x;

            cur += rone[i + 1] * x;
            cur += lone[i] * y;
        }
        else
            lone[i + 1] = lone[i] + s[i] - '0';
        smin(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}