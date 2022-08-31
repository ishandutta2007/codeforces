#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    if (m < n - 1) {
        cout << "NO" << '\n';
        return 0;
    }

    int star = -1;

    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            star = i;

    if (star == -1) {
        cout << (s == t ? "YES" : "NO") << '\n';
        return 0;
    }

    if (t.substr(0, star) == s.substr(0, star) && t.substr(m - (n - star - 1)) == s.substr(star + 1))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}