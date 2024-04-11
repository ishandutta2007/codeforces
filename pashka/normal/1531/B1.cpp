#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> cnt;
    map<pair<int, int>, int> cnt2;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        cnt[x]++;
        if (y != x) {
            cnt[y]++;
            cnt2[{x, y}]++;
        }
    }
    long res = 0;
    for (auto p : cnt) {
        res += p.second * (p.second - 1) / 2;
    }
    for (auto p : cnt2) {
        res -= p.second * (p.second - 1) / 2;
    }
    cout << res << "\n";

    return 0;
}