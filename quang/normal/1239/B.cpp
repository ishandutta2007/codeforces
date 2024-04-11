#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
char s[N];
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> (s + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    if (a[n] != 0) {
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    int shift = min_element(a, a + n) - a;
    rotate(s + 1, s + shift + 1, s + n + 1);
    int res = 0;
    int numZero = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
        res += (a[i] == 0);
    }
    numZero = res;
    pair<int, int> ans(1, 1);
    // 2
    int last = -1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 2) {
            cnt++;
            if (last == -1) last = i;
            if (cnt + numZero > res) {
                res = cnt + numZero;
                ans = {last, i + 1};
            }
        } else if (a[i] < 2) {
            last = -1;
            cnt = 0;
        }
    }

    // 1
    last = -1;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cnt++;
            if (last == -1) last = i;
            if (cnt > res) {
                res = cnt;
                ans = {last, i + 1};
            }
        } else if (a[i] < 1) {
            last = -1;
            cnt = 0;
        }
    }

    auto normalize = [&](int u) {
        if (u <= n - shift) {
            return u + shift;
        }
        return u - (n - shift + 1) + 1;
    };
    cout << res << endl;
    cout << normalize(ans.first) << ' ' << normalize(ans.second) << endl;
    return 0;
}