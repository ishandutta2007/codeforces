#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        if (b.size() > 0 && b.back().first == a[i]) {
            b.back().second++;
        } else {
            b.push_back({a[i], 1});
        }
    }
    if (b.size() < 4) {
        cout << "0 0 0\n";
        return;
    }
    int g = b[0].second;
    int i = 1;
    int s = 0;
    while (s <= g) {
        if (i == n) {
            cout << "0 0 0\n";
            return;
        }
        s += b[i].second;
        i++;
    }
    int br = 0;
    while ((g + s + br + b[i].second) * 2 <= n) {
        if (i == n) {
            cout << "0 0 0\n";
            return;
        }
        br += b[i].second;
        i++;
    }
    if (br <= g) {
        cout << "0 0 0\n";
        return;
    }
    cout << g << " " << s << " " << br << "\n";
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