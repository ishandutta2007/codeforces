#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    char v[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int cnt = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = 1; k < n - 1; k++) {
            if (v[j][k] == '.') {
                if (v[j - 1][k] == '.' && v[j + 1][k] == '.' && v[j][k - 1] == '.' &&  v[j][k + 1] == '.') {
                    cnt++;
                    v[j][k] = v[j - 1][k] = v[j + 1][k] = v[j][k - 1] = v[j][k + 1] = '#';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != '#'){
            	cout << "NO";
            	return 0;
            }
        }
    }
    cout << "YES";
}