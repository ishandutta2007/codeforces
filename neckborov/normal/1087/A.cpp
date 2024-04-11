#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << setprecision(20) << fixed;
    string s;
    cin >> s;
    string t;
    int n = s.length();
    int l = (n - 1) / 2;
    int r = l + 1;
    while (l >= 0 || r < n) {
        if (l >= 0)
            t += s[l--];
        if (r < n)
            t += s[r++];
    }
    cout << t;
}