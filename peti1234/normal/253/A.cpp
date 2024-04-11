#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n, m;
    cin >> n >> m;
    if (n>m) {
        cout << "B";
        n--;
    }
    while (n && m) {
        cout << "GB";
        n--, m--;
    }
    while (n) {
        cout << "B";
        n--;
    }
    while (m) {
        cout << "G";
        m--;
    }
    cout << "\n";
    return 0;
}