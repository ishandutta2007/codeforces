#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int c = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '.' and s[i-1] == '.')
            c += 1;
    }

    while (m--) {
        int pos;
        char ch;
        cin >> pos >> ch; --pos;

        if (s[pos] != '.' and ch == '.') {
            int dot = 0;
            if (pos > 0 and s[pos - 1] == '.') dot += 1;
            if (pos + 1 < n and s[pos + 1] == '.') dot += 1;

            c += dot;
        }

        if (s[pos] == '.' and ch != '.') {
            int dot = 0;
            if (pos > 0 and s[pos - 1] == '.') dot += 1;
            if (pos + 1 < n and s[pos + 1] == '.') dot += 1;

            c -= dot;
        }

        cout << c << "\n";
        s[pos] = ch;
    }
    return 0;
}