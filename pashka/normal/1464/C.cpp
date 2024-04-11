#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    long t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<long> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = 1LL << (s[i] - 'a');
    }
    long x = a[n - 1] - a[n - 2];
    a.pop_back();
    a.pop_back();
    sort(a.rbegin(), a.rend());
    for (long q : a) {
        if (x < t) x += q; else x -= q;
    }
    if (x == t) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}