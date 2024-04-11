#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {

    long m;

    vector<pair<long, long>> build(vector<long> a) {
        vector<pair<long, long>> aa;
        for (long x : a) {
            pair<long, long> t = {x, 1};
            while (t.first % m == 0) {
                t = {t.first / m, t.second * m};
            }
            if (!aa.empty() && aa.back().first == t.first) {
                aa.back().second += t.second;
            } else {
                aa.push_back(t);
            }
        }
        return aa;
    }

    void solve() {
        int n;
        cin >> n >> m;
        vector<long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k;
        cin >> k;
        vector<long> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
        }
        vector<pair<long, long>> aa = build(a);
        vector<pair<long, long>> bb = build(b);
        if (aa == bb) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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