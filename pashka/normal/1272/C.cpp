#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<bool> good(256);
    for (int i = 0; i < k; i++) {
        string ss;
        cin >> ss;
        good[ss[0]] = true;
    }
    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = good[s[i]];
    }
    int last = -1;
    long res = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            last = i;
        } else {
            res += i - last;
        }
    }
    cout << res << "\n";
    return 0;
}