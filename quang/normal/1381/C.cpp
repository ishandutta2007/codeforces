#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, x, y;
int a[N];
vector<int> ls[N];
int res[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> x >> y;
        for (int i = 1; i <= n + 1; i++) {
            ls[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ls[a[i]].push_back(i);
        }
        
        int mex = 1;
        while (!ls[mex].empty()) mex++;

        set<pair<int, int>> s;
        for (int i = 1; i <= n + 1; i++) {
            if (ls[i].empty()) continue;
            s.insert({ls[i].size(), i});
        }
        for (int i = 1; i <= x; i++) {
            auto u = *s.rbegin();
            s.erase(u);
            int color = u.second;
            res[ls[color].back()] = color;
            ls[color].pop_back();
            if (!ls[color].empty()) s.insert({ls[color].size(), color});
        }
        y -= x;

        vector<pair<int, int>> now;
        int maxSize = (n - x) / 2;
        int maxId = -1;
        for (int i = 1; i <= n + 1; i++) {
            if (ls[i].size() > maxSize) {
                maxId = i;
                break;
            }
        }        
        int mod = maxSize;
        if (maxId == -1) {
            for (int i = 1; i <= n + 1; i++) {
                for (int u : ls[i]) {
                    if (y > 0) {
                        y--;
                        now.push_back({i, u});
                    } else {
                        now.push_back({mex, u});
                    }
                }
            }
        } else {
            if (y <= 2 * (n - x - ls[maxId].size())) {
                mod = n - x - ls[maxId].size();
                for (int u : ls[maxId]) {
                    now.push_back({maxId, u});
                }
                for (int i = 1; i <= n + 1; i++) {
                    if (i == maxId) continue;
                    for (int u : ls[i]) {
                        now.push_back({i, u});
                    }
                }
                // for (auto u : now) cout << u.first << ' ' << u.second << endl;
                for (int i = 0; i < now.size() - y; i++) {
                    now[i].first = mex;
                }
            } else {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
        for (int i = 0; i < now.size(); i++) {
            int pos = (i + mod) % now.size();
            res[now[pos].second] = now[i].first;
        }
        for (int i = 1; i <= n; i++) cout << res[i] << ' ';
            cout << '\n';
    }   
    return 0;
}