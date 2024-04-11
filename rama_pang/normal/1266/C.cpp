#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int r, c;
    cin >> r >> c;
    vector<vector<int>> ans(r, vector<int>(c, 0));

    if (r == 1 && c == 1) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (r <= c) ans[i][j] = (r + j + 1) * (i + 1);
            if (r > c) ans[i][j] = (c + i + 1) * (j + 1);
        }
    }

    map<int, int> freq;
    for (int i = 0; i < r; i++) {
        int gcd = ans[i][0];
        for (int j = 0; j < c; j++) {
            gcd = __gcd(gcd, ans[i][j]);
        }
        freq[gcd]++;
    }
    for (int i = 0; i < c; i++) {
        int gcd = ans[0][i];
        for (int j = 0; j < r; j++) {
            gcd = __gcd(gcd, ans[j][i]);
        }
        freq[gcd]++;
    }
    for (auto i : freq) {
        if (i.second > 1) {
            cout << 0 << "\n";
            return 0;
        }
    }
    
    for (auto &i : ans) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    

}