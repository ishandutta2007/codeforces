#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int,int>> v[505050];
int d[505050];
int f[505050][2];
int c[505050];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b) continue;
        v[b].push_back({a,c});
    }
    vector<int> u;
    u.push_back(n);
    for (int i = 0; i < u.size(); i++) {
        int s = u[i];
        for (auto x : v[s]) {
            if (f[x.first][1-x.second]) {
                if (!d[x.first]) {
                    d[x.first] = d[s]+1;
                    u.push_back(x.first);
                }
            } else {
                f[x.first][x.second] = 1;
                c[x.first] = 1-x.second;
            }
        }
    }
    if (n != 1 && d[1] == 0) d[1] = -1;
    cout << d[1] << "\n";
    for (int i = 1; i <= n; i++) cout << c[i];
    cout << "\n";
}