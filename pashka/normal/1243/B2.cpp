#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && s[i] != s[j]) j++;
        if (j == n) {
            int j = i;
            while (j < n && s[i] != t[j]) j++;
            if (j == n) {
                cout << "No\n";
                return;
            } else {
                a.emplace_back(j, j);
                swap(s[j], t[j]);
                a.emplace_back(j, i);
                swap(s[j], t[i]);
            }
        } else {
            a.emplace_back(j, i);
            swap(s[j], t[i]);
        }
    }
    cout << "Yes\n";
    cout << a.size() << "\n";    
    for (auto p : a) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
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