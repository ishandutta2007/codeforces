#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int c1 = 0, c2 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            c1 += 1;
        else
            c2 += 1;
    }

    cout << n - 2 * min(c1, c2);
    return 0;
}