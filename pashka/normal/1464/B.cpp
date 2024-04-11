#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    long x, y;
    cin >> x >> y;
    int l1 = 0;
    int r1 = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') r1++;
    }
    long res = 0;
    vector<long> b;
    for (int i = 0; i < n; i++) {
        int l0 = i - l1;
        int r0 = (n - 1 - i - r1);
        if (s[i] == '1') {
            res += x * l0;
        } else {
            res += y * l1;
        }
        if (s[i] == '1') {
            l1++;
            r1--;
            l0--;
            r0++;
        }
        if (s[i] == '?') {
            s[i] = '0';
            b.push_back(l0 * x + r0 * y - l1 * y - r1 * x);
        }
    }
//    cout << res << "\n";
//    for (auto x : b) {
//        cout << x << " ";
//    }
//    cout << "\n";
    sort(b.begin(), b.end());
    long ss = res;
    long s2 = 0;
    for (int i = 0; i < b.size(); i++) {
        ss += (b[i] + s2);
        s2 -= x + y;
        res = min(res, ss);
    }
    cout << res << "\n";

    return 0;
}