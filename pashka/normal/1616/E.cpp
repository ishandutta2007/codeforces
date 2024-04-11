#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka
struct test {

    vector<int> f;

    void init(int n) {
        f.assign(n + 1, 0);
    }

    long sum(int r) { // exclusive
        if (r == 0)
            return 0;
        r--;
        long result = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            result += f[r];
        return result;
    }

    void inc(int i) {
        for (; i < f.size(); i = (i | (i + 1)))
            f[i] ++;
    }

    int sum(int l, int r) {
        return (r - l + 1) - (sum(r) - sum(l - 1));
    }

    void solve() {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<vector<int>> p(26);
        for (int i = n - 1; i >= 0; i--) {
            p[s[i] - 'a'].push_back(i);
        }
        long res = LLONG_MAX;
        long ss = 0;
        f.resize(n + 1);
        for (int i = 0; i < n; i++) {
            int x = t[i] - 'a';
            for (int j = 0; j < x; j++) {
                if (!p[j].empty()) {
                    int y = p[j].back();
                    res = min(res, ss + y - sum(y));
                }
            }
            if (p[x].empty()) break;
            int y = p[x].back();
            p[x].pop_back();
            ss += y - sum(y);
            inc(y);
        }
        cout << (res == LLONG_MAX ? -1 : res) << "\n";
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