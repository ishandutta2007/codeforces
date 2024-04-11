#include <bits/stdc++.h>

using namespace std;

const vector<pair<char, char>> order = {{'L', 'W'}, {'L', 'G'}, {'G', 'W'}};

const int N = 1e5 + 10;

long long l[N];
string str;

stack<int> stk;

long long calc(char c, long long x) {
    if (c == 'L') return 1 * x;
    else if (c == 'W') return 3 * x;
    else if (c == 'G') return 5 * x;
}
int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> l[i];
    cin >> str;

    /*
    long long ans = 0LL;
    int w = str.length();
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'W') {
            w = i;
            break;
        }
    }

    long long x = 0LL;
    for (int i = 0 ; i < w; ++i) {
        if (str[i] == 'G') {
            x += l[i];
        } else if (str[i] == 'L') {

            long long add = max(0LL, l[i] - x);
            ans += 6 * l[i];

            x -= l[i] - add;
        }
    }

    long long y = 0LL;
    for (int i = w; i < n; ++i) {
        if (str[i] == 'W') {
            y += l[i];
        } else {

            if (y) {
                long long rem = min(y, l[i]);

                ans += 4 * rem;

                y -= rem;
                l[i] -= rem;
            }

            if (x) {
                long long rem = min(x, l[i]);

                ans += 6 * rem;
                x -= rem;
                l[i] -= rem;
            }

            long long add = max(0LL, l[i] - y);
            ans += 4 * l[i];

            y -= l[i] - add;
        }
    }

    ans += (x / 2) * 6 + (x % 2 ? 3 : 0);
    ans += (y / 2) * 4 + (y % 2 ? 2 : 0);

    cout << ans << endl;

    */

    long long ans = 0ll;
    for (auto o : order) {
        char a = o.first, b = o.second;

        while (!stk.empty()) stk.pop();

        for (int i = n-1; i >= 0; --i) {
            if (str[i] == a) {
                stk.push(i);
            } else if (str[i] == b) {
                while (!stk.empty() && l[i]) {
                    long long x = min(l[stk.top()], l[i]);
                    l[stk.top()] -= x;
                    l[i] -= x;

                    ans += x + calc(b, x);
                    if (l[stk.top()] == 0) stk.pop();
                }
            }
        }
    }

    int foundW = 0, foundG = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'W') {
            foundW = 1;
        }
        if (str[i] == 'G') {
            foundG = 1;
        }

        if (str[i] == 'L') {
            if (foundW) {
                ans += l[i] * 4;
            } else {
                ans += l[i] * 6;
            }
        } else if (str[i] == 'G') {
            ans += l[i] * 3;
        } else if (str[i] == 'W') {
            ans += l[i] * 2;
        }
    }

    cout << ans << endl;

    return 0;
}