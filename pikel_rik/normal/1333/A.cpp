#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    string s = "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBW";

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < m; i++)
            cout << s[i];
        cout << "\n";
        for (int i = 1; i < n - 1; i++) {
            for (int j = i % 2; j < m + i % 2; j++)
                cout << s[j];
            cout << "\n";
        }

        if (n % 2 == 0) {
            for (int i = 1; i < m - 1; i++) {
                cout << s[i];
            }
            cout << "BB\n";
        }
        else {
            if (m % 2 != 0) {
                for (int i = 0; i < m; i++) {
                    cout << s[i];
                }
                cout << "\n";
            }
            else {
                for (int i = 0; i < m - 2; i++) {
                    cout << s[i];
                }
                cout << "BB\n";
            }
        }
    }

    return 0;
}