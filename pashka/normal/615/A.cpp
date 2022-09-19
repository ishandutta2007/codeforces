#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <vector>

// @author: pashka

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));

    vector<int> z(m, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int k;
            cin >> k;
            z[k - 1] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        if (!z[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}