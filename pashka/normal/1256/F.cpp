#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int get_p(string s) {
    vector<int> a(26);
    int res = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int x = s[i] - 'a';
        for (int j = 0; j < x; j++) {
            res += a[j];
        }
        a[x]++;
    }
    return res % 2;
}

void solve_test() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    {
        string ss = s;
        string tt = t;
        sort(ss.begin(), ss.end());
        sort(tt.begin(), tt.end());
        if (ss != tt) {
            cout << "NO\n";
            return;
        }
        for (int i = 0; i < n - 1; i++) {
            if (ss[i] == ss[i + 1]) {
                cout << "YES\n";
                return;
            }
        }
    }

    if (get_p(s) != get_p(t)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
 }

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) solve_test();

    return 0;
}