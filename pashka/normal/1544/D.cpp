#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve_test() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> b = a;
        vector<bool> z(n);
        for (int i = 0; i < n; i++) {
            if (z[b[i]]) {
                b[i] = -1;
            } else {
                z[b[i]] = true;
            }
        }

        vector<int> s;
        vector<int> t;
        vector<int> p;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                if (!z[i]) {
                    p.push_back(i);
                } else {
                    t.push_back(i);
                }
            } else if (!z[i]) {
                s.push_back(i);
            }
        }
        if (p.size() == 1 && t.empty() && s.empty()) {
            int x = p[0];
            int y = a[x];
            int z = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] == y) z = i;
            }
            b[z] = x;
            b[x] = y;
        } else {
            if (p.size() > 1) {
                for (int i = 0; i < p.size(); i++) {
                    int x = p[i];
                    int y = p[(i + 1) % p.size()];
                    b[x] = y;
                }
                p.clear();
            }
            for (int i = 0; i < s.size(); i++) {
                int x = t[i];
                int y = s[i];
                while (!p.empty()) {
                    int xx = p.back();
                    p.pop_back();
                    b[x] = xx;
                    x = xx;
                }
                b[x] = y;
            }
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) k++;
        }
        cout << k << "\n";
        for (int i = 0; i < n; i++) {
            cout << b[i] + 1 << " ";
        }
        cout << "\n";

    }
};


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve_test();
    }

    return 0;
}