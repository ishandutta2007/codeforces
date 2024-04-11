#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char a[111][111];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++){
        for (int j=0;j<=m;j++) a[i][j] = 0;
    }
    while(true){
        bool flag = 0;
        int x, y;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) if (!a[i][j] && ((i==0 || i==n-1) || (j==0 || j==m-1))){
                flag = 1, x = i, y = j;
                break;
            }
            if (flag) break;
        }
        if (!flag) break;
        a[x][y] = '1';
        for (int k=0;k<8;k++){
            int nx = x+dx[k], ny = y+dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            a[nx][ny] = '0';
        }
    }
    for (int i=1;i<n-1;i++){
        for (int j=1;j<m-1;j++) a[i][j] = '0';
    }

    for (int i=0;i<n;i++) printf("%s\n", a[i]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}