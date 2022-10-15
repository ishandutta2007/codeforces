#include <iostream>
#include <vector>

using namespace std;

int n;
int c[202020];
int p[3][202020];
int z[202020];
vector<pair<int,int>> v[202020];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) c[i] = z[i] = 0;
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int j = 1; j <= 2; j++) {
            for (int i = 1; i <= n; i++) {
                cin >> p[j][i];
                v[p[j][i]].push_back({j,i});
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (v[i].size() != 2) ok = false;
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        vector<int> r;
        for (int i = 1; i <= n; i++) {
            if (z[i]) continue;
            if (p[1][i] == p[2][i]) continue;
            int k = p[2][i];
            int w = i;
            vector<pair<int,int>> q;
            q.push_back({w,1});
            while (true) {
                z[w] = 1;
                auto t = v[k][0];
                if (t.second == w) t = v[k][1];
                k = p[3-t.first][t.second];
                w = t.second;
                if (z[w]) break;
                q.push_back({t.second,t.first==1});
            }
            int c0 = 0, c1 = 0;
            for (auto x : q) {
                if (x.second == 0) c0++;
                if (x.second == 1) c1++;
            }
            if (c0 > c1) {
                for (auto x : q) if (x.second == 1) r.push_back(x.first);
            } else {
                for (auto x : q) if (x.second == 0) r.push_back(x.first);
            }
        }
        cout << r.size() << "\n";
        for (auto x : r) cout << x << " ";
        cout << "\n";
    }
}