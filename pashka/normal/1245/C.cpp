#include <bits/stdc++.h>

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
    }

    vector<long> d(n + 1);
    d[0] = 1;

    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1];
        if (i >= 2 && (s[i - 1] == 'u' && s[i - 2] == 'u')) {
            d[i] += d[i - 2];
        }
        if (i >= 2 && (s[i - 1] == 'n' && s[i - 2] == 'n')) {
            d[i] += d[i - 2];
        }
        d[i] %= 1000000007;
    }
    cout << d[n];

    return 0;
}