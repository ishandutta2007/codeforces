#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 501;

char diff(char c1, char c2) {
    if (c1 != 'a' and c2 != 'a')
        return 'a';
    if (c1 != 'b' and c2 != 'b')
        return 'b';
    return 'c';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, t;
    cin >> n >> t;
    t = n - t;

    string s1, s2;
    cin >> s1 >> s2;

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i])
            c += 1;
    }

    if (c < t and n - c < 2 * (t - c)) {
        cout << "-1\n";
        return 0;
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i] and t) {
            ans.push_back(s1[i]);
            t -= 1;
        }
        else ans.push_back('.');
    }

    int t1 = t, t2 = t;
    for (int i = 0; i < n; i++) {
        if (t1 == 0 and t2 == 0 and ans[i] == '.')
            ans[i] = diff(s1[i], s2[i]);

        if (t1 != 0 and ans[i] == '.') {
            ans[i] = s1[i];
            t1 -= 1;
        }
        else if (t2 != 0 and ans[i] == '.') {
            ans[i] = s2[i];
            t2 -= 1;
        }
    }

    cout << ans << "\n";
    return 0;
}