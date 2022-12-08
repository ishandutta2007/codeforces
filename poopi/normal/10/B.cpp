                        /* in the name of Allah */
#include<iostream>
#include<cmath>
using namespace std;

#define INF 100000000

int n, k, m, cen;
int dp[100][100][100];
int sz[100][100];
bool mark[100][100];

int mem(int r, int c, int t){
    if(dp[r][c][t] != -1)
        return dp[r][c][t];
    if(k - c < t)
        return dp[r][c][t] = INF;
    if(t == 0)
        return dp[r][c][t] = 0;
    return dp[r][c][t] = min(INF, abs(r - cen) + abs(c - cen) + mem(r, c + 1, t - 1));
}

void setSz(int r){
    for(int j = k - 1; j >= 0; j--){
        if(!mark[r][j])
            sz[r][j] = sz[r][j + 1] + 1;
        else sz[r][j] = 0;
    }
}

int main(){
    cin >> n >> k;
    cen = k / 2;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < k; i++)
        setSz(i);
    for(int i = 0; i < n; i++){
        cin >> m;
        int mn = INF, x = -1, y = -1;
        for(int r = 0; r < k; r++){
            for(int c = 0; c < k; c++){
                if(sz[r][c] < m) continue;
                if(mem(r, c, m) < mn){
                    mn = dp[r][c][m];
                    x = r, y = c;
                }
            }
        }
        if(mn == INF)
            cout << -1 << endl;
        else{
            cout << x + 1 << ' ' << y + 1 << ' ' << y + m << endl;
            for(int c = y; c < y + m; c++)
                mark[x][c] = true;
            setSz(x);
        }
    }
    return 0;
}