#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        vector<int> check(n, 0);
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            int foo = (i + a[i]) % n;
            if (foo < 0) foo += n;
            if (check[foo]) ok = 0;
            check[foo] = 1;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}