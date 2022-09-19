#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    vector<int> p;
    vector<int> s1, s2;

    int get(int x) {
        if (p[x] != x) p[x] = get(p[x]);
        return p[x];
    }

    void solve_test() {
        int n, m;
        cin >> n >> m;
        p.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        s1.assign(n, 1);
        s2.resize(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x = get(x - 1);
            y = get(y - 1);
            if (p[x] != p[y]) {
                p[y] = x;
                s1[x] += s1[y];
                s2[x] += s2[y];
            }
            s2[x]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == i) {
//                cout << i << " " << s1[i] << " " << s2[i] << "\n";
                if (s1[i] > 1) {
                    if (s1[i] == s2[i]) {
                        res += s2[i] + 1;
                    } else {
                        res += s2[i];
                    }
                }
            }
        }
        cout << res << "\n";
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