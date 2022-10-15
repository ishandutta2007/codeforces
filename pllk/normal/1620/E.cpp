#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

vector<int> v[1000001];
set<pair<int,int>> s;
int r[1000001];

void dfs(int u, int k) {
    if (v[k].size()) {
        for (auto g : v[k]) dfs(u, g);
    } else {
        r[k] = u;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    int c = 0;
    int d = 500000;
    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            c++;
            s.insert({x,c});
        } else {
            int x, y;
            cin >> x >> y;
            d++;
            auto it = s.lower_bound({x,0});
            while (it != s.end() && it->first == x) {
                v[d].push_back(it->second);
                auto v = it;
                it++;
                s.erase(v);
            }
            s.insert({y,d});
        }
    }
    for (auto p : s) {
        dfs(p.first, p.second);
    }
    for (int i = 1; i <= c; i++) cout << r[i] << " ";
    cout << "\n";
}