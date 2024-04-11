#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k = n;
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1] > s[i]) {
                k = i + 1;
                break;
            }
        }
        string s1 = s.substr(0, k);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        string res = s1 + s2;
        string t = s.substr(0, 1);
        t = t + t;
        if (t < res) res = t;
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}