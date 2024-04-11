#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>


// @author: pashka

#define BUBEN 300
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n + 1);
    p[0] = 0;
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] ^ a[i];
    }

    vector<int> l(m);
    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]++;
    }

    vector<long long> res(m);

    for (int i = 0; i < n; i += BUBEN) {
        vector<pair<int, int>> g;
        for (int j = 0; j < m; j++) {
            if (l[j] >= i && l[j] < i + BUBEN) {
                g.push_back(make_pair(r[j], j));
            }
        }
        sort(g.begin(), g.end());
        int ll = 0;
        int rr = 0;
        vector<int> cur(2000000, 0);
        long long s = 0;

        for (auto q : g) {
            while (rr < q.first) {
                s += cur[p[rr] ^ k];
                cur[p[rr]]++;
                rr++;
            }
            while (ll < l[q.second]) {
                cur[p[ll]]--;
                s -= cur[p[ll] ^ k];
                ll++;
            }
            while (ll > l[q.second]) {
                ll--;
                s += cur[p[ll] ^ k];
                cur[p[ll]]++;
            }
            res[q.second] = s;
        }
    }

    for (auto item : res) {
        cout << item << endl;
    }

    return 0;
}