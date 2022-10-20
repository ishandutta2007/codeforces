#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define int long long
using namespace std;
const int maxn = 300;
const double eps = 1e-10;
int a[maxn][maxn], e[maxn][3];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        memset(a, -1, sizeof(a));
        map<pii, int> mp;
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            if(w == -1) w = 0;
            a[u][v] = a[v][u] = w;
            mp[{u,v}] = mp[{v,u}] = i;
            e[i][0] = u;
            e[i][1] = v;
            e[i][2] = w;
        }
        vector<vector<int>> mat;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(a[i][j] != -1 && a[i][k] != -1 && a[j][k] != -1) {
                        vector<int> vec(m+1);
                        if(a[i][j] == 0) vec[mp[{i,j}]] = 1;
                        if(a[i][k] == 0) vec[mp[{i,k}]] = 1;
                        if(a[k][j] == 0) vec[mp[{k,j}]] = 1;
                        vec[m] = (27 - a[i][j] - a[j][k] - a[i][k]) % 3;
                        mat.push_back(vec);
                    }
                }
            }
        }
        int u = mat.size(), v = m+1;
        for(int i = 0; i < v-1; i++) {
            int tar = -1;
            for(int j = i; j < u; j++) {
                if(mat[j][i]) {
                    tar = j;
                    break;
                }
            }
            if(tar == -1) {
                vector<int> vec(m+1);
                vec[i] = 1;
                vec[m] = a[e[i][0]][e[i][1]];
                mat.push_back(vec);
                tar = u;
                u++;
            }
            swap(mat[i], mat[tar]);
            if(mat[i][i] == 2) {
                for(int k = 0; k < v; k++) mat[i][k] = mat[i][k] * 2 % 3;
            }
            for(int j = i+1; j < u; j++) {
                if(mat[j][i]) {
                    int mul = mat[j][i];
                    for(int k = 0; k < v; k++) {
                        mat[j][k] = mat[j][k] - mul * mat[i][k];
                        mat[j][k] = (mat[j][k] % 3 + 3) % 3;
                    }
                }
            }
        }
        for(int i = v-2; i >= 0; i--) {
            for(int j = 0; j < i; j++) {
                int mul = mat[j][i];
                for(int k = 0; k < v; k++) {
                    mat[j][k] = mat[j][k] - mul * mat[i][k];
                    mat[j][k] = (mat[j][k] % 3 + 3) % 3;
                }
            }
        }
        for(int i = 0; i < m; i++) a[e[i][0]][e[i][1]] = a[e[i][1]][e[i][0]] = mat[i][m];
        /*for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
            cout << endl;
        }*/
        int ok = 1;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(a[i][j] != -1 && a[i][k] != -1 && a[j][k] != -1) {
                        if((a[i][j] + a[j][k] + a[k][i]) % 3) ok = 0;
                    }
                }
            }
        }
        if(ok) {
            for(int i = 0; i < m; i++) {
                int ans = a[e[i][0]][e[i][1]];
                if(ans == 0) ans = 3;
                cout << ans << " ";
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}