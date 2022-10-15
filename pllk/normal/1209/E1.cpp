#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int x[10][111];

void lol() {
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> x[i][j];
            v.push_back({x[i][j],i,j});
        }
    }
    sort(v.rbegin(),v.rend());
    if (n <= 3) {
        int u = 0;
        for (int i = 0; i < n; i++) u += v[i][0];
        cout << u << "\n";
    } else {
        int r = min(20,(int)v.size());
        int h = 0;
        for (int a = 0; a < r; a++) {
        for (int b = a+1; b < r; b++) {
        for (int c = b+1; c < r; c++) {
        for (int d = c+1; d < r; d++) {
            int u = v[a][0]+v[b][0]+v[c][0]+v[d][0];
            vector<vector<int>> z;
            z.push_back({v[a][2],v[a][1]});
            z.push_back({v[b][2],v[b][1]});
            z.push_back({v[c][2],v[c][1]});
            z.push_back({v[d][2],v[d][1]});
            sort(z.begin(),z.end());
            bool ok = true;
            if (z[0][0] == z[1][0] && z[2][0] == z[3][0] && z[1][0] != z[2][0]) {
                if (z[0][1]%2 == z[1][1]%2 && z[2][1]%2 != z[3][1]%2) ok = false;
                if (z[0][1]%2 != z[1][1]%2 && z[2][1]%2 == z[3][1]%2) ok = false;
            }
            if (!ok) continue;
            h = max(h,u);
        }
        }
        }
        }
        cout << h << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) lol();
}