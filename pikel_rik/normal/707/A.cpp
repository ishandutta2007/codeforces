#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char> (m));

    int flag1 = 0, flag2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'W' or a[i][j] == 'B' or a[i][j] == 'G')
                flag1 = 1;
            else
                flag2 = 1;
        }
    }

    if (flag2 == 1)
        cout << "#Color";
    else
        cout << "#Black&White";

    return 0;
}