#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m, p;
int t[333][333];
vector<pair<int,int>> z[333*333];
ll d[333][333];

int rr[333][333];
ll rx[333][333];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> t[i][j];
            z[t[i][j]].push_back({i,j});
            d[i][j] = 99999999999999999LL;
            if (t[i][j] == 1) d[i][j] = abs(i-1)+abs(j-1);
        }
    }
    for (int i = 1; i <= p-1; i++) {
        int s = z[i].size();
        if (s*s <= 3*n*m) {
            for (int j = 0; j < z[i].size(); j++) {
                int y = z[i][j].first;
                int x = z[i][j].second;
                for (int e = 0; e < z[i+1].size(); e++) {
                    int uy = z[i+1][e].first;
                    int ux = z[i+1][e].second;
                    d[uy][ux] = min(d[uy][ux],d[y][x]+abs(y-uy)+abs(x-ux));
                }
            }
        } else {
            vector<pair<ll,int>> u;
            for (int j = 0; j < z[i].size(); j++) {
                ll k = d[z[i][j].first][z[i][j].second];
                u.push_back({k,j});
            }
            sort(u.begin(),u.end());
            vector<pair<int,int>> w;
            int ay = z[i][u[0].second].first;
            int ax = z[i][u[0].second].second;
            w.push_back({ay,ax});
            rr[ay][ax] = i;
            rx[ay][ax] = u[0].first;
            int k = 0;
            for (int j = 0; j < w.size(); j++) {
                int uy = w[j].first;
                int ux = w[j].second;
                ll ud = rx[uy][ux];
                while (k+1 < u.size() && u[k+1].first == ud) {
                    int ty = z[i][u[k+1].second].first;
                    int tx = z[i][u[k+1].second].second;
                    if (rr[ty][tx] != i || rx[ty][tx] > ud) {
                        w.push_back({ty,tx});
                        rr[ty][tx] = i;
                        rx[ty][tx] = ud;
                    }
                    k++;
                }
                int f[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
                for (int k = 0; k < 4; k++) {
                    int fy = uy+f[k][0];
                    int fx = ux+f[k][1];
                    if (fy < 1 || fy > n || fx < 1 || fx > m) continue;
                    if (rr[fy][fx] == i && rx[fy][fx] <= ud+1) continue;
                    w.push_back({fy,fx});
                    rr[fy][fx] = i;
                    rx[fy][fx] = ud+1;
                    if (t[fy][fx] == i+1) d[fy][fx] = ud+1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (t[i][j] == p) {
                cout << d[i][j] << "\n";
                return 0;
            }
        }
    }
}