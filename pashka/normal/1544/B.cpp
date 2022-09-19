#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve_test() {
        int n, m;
        cin >> n >> m;
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < n - 1; i++) {
            x.push_back(i);
            y.push_back(0);
        }
        for (int i = 0; i < m - 1; i++) {
            y.push_back(i);
            x.push_back(n- 1);
        }
        for (int i = n - 1; i > 0; i--) {
            x.push_back(i);
            y.push_back(m - 1);
        }
        for (int i = m - 1; i > 0; i--) {
            y.push_back(i);
            x.push_back(0);
        }
        int xx = -10;
        int yy = -10;
        vector<string> res(n, string(m, '0'));
        for (int i = 0; i < (int)x.size() - 1; i++) {
            if (abs(x[i] - xx) > 1 || abs(y[i] - yy) > 1) {
                xx = x[i];
                yy = y[i];
                res[xx][yy] = '1';
            }
        }
        for (auto s : res) {
            cout << s << "\n";
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