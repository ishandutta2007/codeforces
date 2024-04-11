#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

bool win1(vector<int> &a, int n, int k) {
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }
    for (int i = 0; i <= n - k; i++) {
        if (p[i] == 0 && (p[n] - p[i + k] == 0)) {
            return true;
        }
    }
    return false;
}

bool win2(vector<int> &a, int n, int k) {
    vector<int> p(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
    }
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            l[i] = i;
        } else {
            l[i] = i == 0 ? -1 : l[i - 1];
        }
    }
    vector<int> r(n);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i]) {
            r[i] = i;
        } else {
            r[i] = i == n - 1 ? -1 : r[i + 1];
        }
    }
    for (int i = 0; i <= n - k; i++) {
        if (p[i] > 0 && (p[n] - p[i + k] > 0)) {
            return false;
        }
        if (p[i] > 0) {
            if (l[i - 1] - r[0] + 1 > k) return false;
        }
        if (p[n] - p[i + k] > 0) {
            if (l[n - 1] - r[i + k] + 1 > k) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] == '1';
    }
    for (int t = 0; t < 2; t++) {
        if (win1(a, n, k)) {
            cout << "tokitsukaze\n";
            return 0;
        }
        for (int i = 0; i < n; i++) {
            a[i] ^= 1;
        }
    }
    for (int t = 0; t < 2; t++) {
        if (!win2(a, n, k)) {
            cout << "once again\n";
            return 0;
        }
        for (int i = 0; i < n; i++) {
            a[i] ^= 1;
        }
    }
    cout << "quailty\n";

    return 0;
}