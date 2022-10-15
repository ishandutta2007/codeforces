#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, k;
vector<int> v[202020];
int d[202020];
int z[202020];
vector<int> w[202020];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            d[i] = 0;
            z[i] = 0;
            w[i].clear();
        }
        for (int i = 1; i <= n-1; i++) {
            int a, b;
            cin >> a >> b;
            d[a]++; d[b]++;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if (n == 2) {
            cout << (k == 1) << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] == 1) w[v[i][0]].push_back(i);
        }
        set<pair<int,int>> s;
        for (int i = 1; i <= n; i++) {
            s.insert({w[i].size(),i});
        }
        int u = 0;
        while (s.size()) {
            auto p = *s.rbegin();
            if (p.first < k) break;
            u++;
            s.erase(p);
            p.first -= k;
            int x = p.second;
            for (int i = 0; i < k; i++) {
                z[w[x].back()] = 1;
                w[x].pop_back();
                d[x]--;
            }
            if (p.first == 0 && d[x] == 1) {
                for (auto u : v[x]) {
                    if (!z[u]) {
                        s.erase({w[u].size(),u});
                        w[u].push_back(x);
                        s.insert({w[u].size(),u});
                    }
                }
            } else {
                s.insert(p);
            }
        }
        cout << u << "\n";
    }
}