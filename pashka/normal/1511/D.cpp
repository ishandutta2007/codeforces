#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> s;
    vector<vector<bool>> z(k, vector<bool>(k));
    s.push_back(0);
    z[0][0] = true;
    for (int i = 0; i < k * k - 1; i++) {
        int j = k - 1;
        while (z[s.back()][j]) j--;
        z[s.back()][j] = true;
        s.push_back(j);
    }
    cout << 'a';
    for (int i = 0; i < n - 1; i++) {
        cout << (char)('a' + s[i % s.size()]);
    }

    return 0;
}