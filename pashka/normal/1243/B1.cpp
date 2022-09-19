#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            a.push_back(i);
        }
    }
    if (a.size() > 2 || a.size() == 1) {
        cout << "No\n";
        return;
    }
    if (a.size() == 2) {
        swap(s[a[0]], t[a[1]]);
        if (s == t) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}