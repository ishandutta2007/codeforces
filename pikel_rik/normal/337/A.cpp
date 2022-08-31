#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> f(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }
    sort(f.begin(), f.end());
    int min = INT_MAX;
    for (int i = 0; i < m-n+1; i++) {
        if (f[i+n-1] - f[i] < min)
            min = f[i+n-1] - f[i];
    }
    cout << min;
    return 0;
}