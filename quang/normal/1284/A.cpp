#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, m;
string s[N], t[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        y--;
        cout << s[y % n] << t[y % m] << '\n'; 
    }
    return 0;
}