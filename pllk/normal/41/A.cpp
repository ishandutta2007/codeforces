#include <iostream>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    int v = 0;
    if (a.length() != b.length()) v = 1;
    int n = a.length();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[n-i-1]) v = 1;
    }
    if (v == 0) cout << "YES\n";
    else cout << "NO\n";
}