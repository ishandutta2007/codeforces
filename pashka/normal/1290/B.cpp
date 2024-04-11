#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n;
    cin >> n;
    int m = s.size();
    vector<vector<int>> p(26, vector<int>(m + 1));
    for (int x = 0; x < 26; x++) {
        for (int i = 0; i < m; i++) {
            p[x][i + 1] = p[x][i];
            if (s[i] - 'a' == x) {
                p[x][i + 1]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        if (s[l] != s[r - 1]) {
            cout << "Yes\n";
            continue;
        }
        if (r - l == 1) {
            cout << "Yes\n";
            continue;
        }
        int c = 0;
        for (int j = 0; j < 26; j++) {
            if (p[j][r] > p[j][l]) c++;
        }
        if (c >= 3) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
        continue;
    }

    return 0;
}