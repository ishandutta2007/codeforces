#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        map<int, int> a;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[abs(x)]++;
        }
        int s = 0;
        for (auto p : a) {
            s += min(p.second, p.first == 0 ? 1 : 2);
        }
        cout << s << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}