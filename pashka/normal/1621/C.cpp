#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<bool> z(n);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            if (z[i]) continue;
            vector<int> q;
            while (true) {
                cout << "? " << i + 1 << endl;
                int x;
                cin >> x;
                x--;
                if (z[x]) break;
                q.push_back(x);
                z[x] = true;
            }
            int k = q.size();
            for (int j = 0; j < k; j++) {
                p[q[j]] = q[(j + 1) % k];
            }
        }
        cout << "! ";
        for (int x : p) cout << x + 1 << " ";
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}