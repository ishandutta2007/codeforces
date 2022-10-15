#include <iostream>

using namespace std;

#define ll long long

int n, m, k;
string t[2222];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int j = 0; j < m; j++) {
        ll c = 0;
        for (int i = 0; i < n; i++) {
            if (j-i >= 0 && t[i][j-i] == 'R') c++;
            if (j+i <= m-1 && t[i][j+i] == 'L') c++;
            if (i+i <= n-1 && t[i+i][j] == 'U') c++;
        }
        cout << c << " ";
    }
    cout << "\n";
}