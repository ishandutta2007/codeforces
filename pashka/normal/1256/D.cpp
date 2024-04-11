#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    long k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> z;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') z.push_back(i);
    }

    for (int i = 0; i < (int)z.size(); i++) {
        long x;
        if (i == 0) x = z[i]; else x = z[i] - z[i - 1] - 1;
        x = min(x, k);
        z[i] -= x;
        k -= x;        
    }

    s = string(n, '1');
    for (int i : z) {
        s[i] = '0';
    }
    cout << s << "\n";

}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) solve_test();

    return 0;
}