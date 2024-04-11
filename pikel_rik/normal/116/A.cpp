#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int> (2, 0));
    int current = 0;
    int m = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        current += v[i][1] - v[i][0];
        if (current > m)
            m = current;
    }

    cout << m;

    return 0;
}