#include <bits/stdc++.h>
#define MAXN 3001
#define zeros(x) (x & (-x))

using namespace std;

char mat[MAXN + 1][MAXN + 1];
int l[MAXN + 1][MAXN + 1], r[MAXN + 1][MAXN + 1];
int d[MAXN + 1][MAXN + 1];
int aib[2 * MAXN + 1][MAXN + 1];

vector < pair <int, int> > cell[MAXN + 1];

inline void update(int l, int p, int m) {
    for(int i = p; i <= m; i += zeros(i))
        aib[l][i]++;
}

inline int query(int l, int p) {
    int ans = 0;
    for(int i = p; i > 0; i -= zeros(i))
        ans += aib[l][i];
    return ans;
}

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
       for(j = 1; j <= m; j++)
          cin >> mat[i][j];
    for(i = n; i >= 1; i--) {
       for(j = 1; j <= m; j++)
           if(mat[i][j] == 'z') {
               l[i][j] = 1;
               l[i][j] += l[i][j - 1];
            }
       for(j = m; j >= 1; j--)
           if(mat[i][j] == 'z') {
               r[i][j] = 1;
               r[i][j] += r[i][j + 1];
            }
       for(j = 1; j <= m; j++)
           if(mat[i][j] == 'z') {
               d[i][j] = 1;
               d[i][j] += d[i + 1][j - 1];
            }
    }
    for(i = 1; i <= n; i++)
       for(j = 1; j <= m; j++)
          cell[j + r[i][j] - 1].push_back({i, j});
    long long ans = 0;
    for(j = m; j >= 1; j--) {
       for(auto it : cell[j])
          update(it.first + it.second, it.second, m);
       for(i = 1; i <= n; i++) {
          int len = min(l[i][j], d[i][j]);
          ans += query(i + j, j) - query(i + j, j - len);
       }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}