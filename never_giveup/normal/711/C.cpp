#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 110;

const ll inf = 1e18 + 100;

int n, m, k;

int a[maxn];

ll p[maxn][maxn];

ll q[maxn][maxn][maxn];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> p[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++)
            for (int r = 1; r <= m; r++)
                q[i][j][r] = inf;
    if (a[0] == 0)
        for (int i = 1; i <= m; i++)
            q[0][1][i] = p[0][i - 1];
    else
        q[0][1][a[0]] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 1; j <= n; j++)
            for (int r = 1; r <= m; r++)
            if (q[i][j][r] != inf){
                if (a[i + 1] == 0)
                    for (int nxt = 1; nxt <= m; nxt++)
                        if (nxt == r)
                            q[i + 1][j][r] = min(q[i + 1][j][r], q[i][j][r] + p[i + 1][nxt - 1]);
                        else
                            q[i + 1][j + 1][nxt] = min(q[i + 1][j + 1][nxt], q[i][j][r] + p[i + 1][nxt - 1]);
                else{
                    int nxt = a[i + 1];
                    if (nxt == r)
                        q[i + 1][j][r] = min(q[i + 1][j][r], q[i][j][r]);
                    else
                        q[i + 1][j + 1][nxt] = min(q[i + 1][j + 1][nxt], q[i][j][r]);
                }
            }
    ll answer = inf;
    for (int i = 1; i <= m; i++)
        answer = min(answer, q[n - 1][k][i]);
    if (answer == inf)
        answer = -1;
    cout << answer;
}