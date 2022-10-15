#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v[3333];
int d[3333][3333];
int e[3333];
vector<pair<int,int>> l1[3333];
vector<pair<int,int>> l2[3333];

int p;
int pa,pb,pc,pd;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) continue;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        vector<pair<int,int>> u;
        u.push_back({i,0});
        d[i][i] = 0;
        e[i] = i;
        for (int j = 0; j < u.size(); j++) {
            int v1 = u[j].first;
            int v2 = u[j].second;
            for (int k = 0; k < v[v1].size(); k++) {
                if (e[v[v1][k]] == i) continue;
                e[v[v1][k]] = i;
                d[i][v[v1][k]] = v2+1;
                u.push_back({v[v1][k],v2+1});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || d[i][j] == 0) continue;
            int u = d[i][j];
            l1[i].push_back({-u,j});
            if (l1[i].size() > 4) {
                sort(l1[i].begin(),l1[i].end());
                l1[i].pop_back();
            }
        }
        for (int j = 1; j <= n; j++) {
            if (i == j || d[j][i] == 0) continue;
            int u = d[j][i];
            l2[i].push_back({-u,j});
            if (l2[i].size() > 4) {
                sort(l2[i].begin(),l2[i].end());
                l2[i].pop_back();
            }
        }
    }
    
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) continue;
            int u = d[a][b];
            if (u == 0) continue;
            for (int ui = 0; ui < l1[b].size(); ui++) {
                for (int uj = 0; uj < l2[a].size(); uj++) {
                    if (l1[b][ui].second == a) continue;
                    if (l2[a][uj].second == b) continue;
                    if (l1[b][ui].second == l2[a][uj].second) continue;
                    int u2 = u-l1[b][ui].first-l2[a][uj].first;
                    if (u2 > p) {
                        p = u2;
                        pa = a;
                        pb = b;
                        pd = l1[b][ui].second;
                        pc = l2[a][uj].second;
                    }
                }
            }
        }
    }
    cout << pc << " " << pa << " " << pb << " " << pd << "\n";
}