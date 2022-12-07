#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
int fpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = 1LL * ret * a % mod;
        b >>= 1;
        a = 1LL * a * a % mod;
    }
    return ret;
}
 
const int N = 122;
 
int g[N * N];
int cnt = 0;
int id[N][N];
vector < vector < int > > mv;
 
int main() {
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);
 
    int R; int a[4];
    cin >> R >> a[0] >> a[1] >> a[2] >> a[3];
 
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
 
    int inv = fpow(a[0] + a[1] + a[2] + a[3], mod - 2);
    for(int i = 0; i < 4; ++i) a[i] = (1LL * a[i] * inv % mod);
 
    memset(id, -1, sizeof id);
    for(int x = 0; x <= 100; ++x) {
        for(int y = 0; y <= 100; ++y) {
            if((x - 50) * (x - 50) + (y - 50) * (y - 50) > R * R) continue;
            id[x][y] = cnt++;
        }
    }
 
    mv.resize(cnt, vector < int >(cnt, 0));
 
    for(int x = 0; x <= 100; ++x) {
        for(int y = 0; y <= 100; ++y) {
            if(id[x][y] == -1) continue;
            g[id[x][y]] = mv[id[x][y]][id[x][y]] = mod - 1;
            for(int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 0 || ny < 0 || id[nx][ny] == -1) continue;
                mv[id[x][y]][id[nx][ny]] = a[d];
            }
        }
    }
 
    for(int i = 0; i < cnt; ++i) {
        for(int j = 0; j < N; ++j) if(i + j < cnt && mv[i + j][i]) {
            swap(mv[i], mv[i + j]);
            break;
        }
 
        for(int j = 1; j < N; ++j) if(i + j < cnt) {
            int mul = 1LL * mv[j + i][i] * fpow(mv[i][i], mod - 2) % mod;
            for(int k = 0; k < N; ++k) if(i + k < cnt) {
                mv[i + j][i + k] = (mv[i + j][i + k] - 1LL * mul * mv[i][i + k] + 1LL * mod * mod) % mod;
            }
            g[j + i] = (g[j + i] - 1LL * g[i] * mul + 1LL * mod * mod) % mod;
        }
    }
 
    for(int i = cnt - 1; i >= 0; --i) {
        for(int j = i + 1; j < cnt; ++j) {
            g[i] = (g[i] - 1LL * mv[i][j] * g[j] + 1LL * mod * mod) % mod;
        }
        g[i] = 1LL * g[i] * fpow(mv[i][i], mod - 2) % mod;
    }
 
    cout << g[id[50][50]] << endl;
 
    return 0;
}