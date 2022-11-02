#include<bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif

    int n;
    cin >> n;
    string a[n];
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 5;j += 3) {
            if (a[i][j] == a[i][j + 1] && a[i][j] == 'O') {
                a[i][j] = '+';
                a[i][j + 1] = '+';
                cout << "YES" << '\n';
                for(int q = 0;q < n;q++) {
                    cout << a[q] << '\n';
                }
                return 0;
            }
        }
    }
    cout << "NO";
}