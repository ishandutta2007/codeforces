#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        string d;
        cin >> d;
        if (k == 0 && d != "South") {
            cout << "NO\n";
            return 0;
        }
        if (k == 20000 && d != "North") {
            cout << "NO\n";
            return 0;
        }
        if (d == "West" || d == "East") continue;
        for (int j = 1; j <= t; j++) {
            if (k == 0 && d != "South") {
                cout << "NO\n";
                return 0;
            }
            if (k == 20000 && d != "North") {
                cout << "NO\n";
                return 0;
            }
            if (d == "South") k++;
            if (d == "North") k--;
        }
    }
    if (k != 0) cout << "NO\n";
    else cout << "YES\n";
}