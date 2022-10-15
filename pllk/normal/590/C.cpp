#include <iostream>
#include <vector>

using namespace std;

int n, m;
string s[1111];

#define A 99999999

int mm[4][1111][1111];

void haku(int k) {
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '0'+k) {
                mm[k][i][j] = 0;
                v.push_back({i,j});
            } else {
                mm[k][i][j] = A;
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].first;
        int x = v[i].second;
        int d = mm[k][y][x];
        int ss[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int j = 0; j < 4; j++) {
            int uy = y+ss[j][0];
            int ux = x+ss[j][1];
            if (uy < 0 || uy >= n || ux < 0 || ux >= m) continue;
            if (s[uy][ux] == '#') continue;
            if (mm[k][uy][ux] <= d+1) continue;
            mm[k][uy][ux] = d+1;
            v.push_back({uy,ux});
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    haku(1);
    haku(2);
    haku(3);
    int x = A;
    for (int i = 1; i <= 3; i++) {
        int p[4];
        p[1] = p[2] = p[3] = A;
        p[i] = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (s[y][x] != '0'+i) continue;
                if (i != 1) p[1] = min(p[1],mm[1][y][x]-1);
                if (i != 2) p[2] = min(p[2],mm[2][y][x]-1);
                if (i != 3) p[3] = min(p[3],mm[3][y][x]-1);
            }
        }
        x = min(x,p[1]+p[2]+p[3]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') continue;
            if (s[i][j] == '2') continue;
            if (s[i][j] == '3') continue;
            if (s[i][j] == '#') continue;
            int u = mm[1][i][j]+mm[2][i][j]+mm[3][i][j]-2;
            x = min(x,u);
        }
    }
    if (x > n*m) x = -1;
    cout << x << "\n";
}