#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (s[i] == '-')
                c2 += 1;
            else c1 += 1;
        }
        else {
            if (s[i] == '+')
                c2 += 1;
            else c1 += 1;
        }
    }

    c1 == c2 ? cout << "Yes" : cout << "No";
    return 0;
}