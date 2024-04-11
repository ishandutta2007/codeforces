#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char matrix[1010][1010];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool visited[1010][1010], chk1[1010], chk2[1010];
int n, m;
vector<int> tmpx, tmpy;

void dfs(int x, int y){
    if (visited[x][y] || matrix[x][y]=='.') return;
    visited[x][y] = 1;
    for (int k=0;k<4;k++){
        int nxtx = x + dx[k], nxty = y + dy[k];
        if (nxtx>=0 && nxtx<n && nxty>=0 && nxty<m) dfs(nxtx, nxty);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++) scanf("%s", matrix[i]);
    for (int i=0;i<n;i++){
        bool tmp1=0;
        for (int j=0;j<m;j++) if (matrix[i][j] == '#') tmp1=1;
        if (!tmp1) tmpx.push_back(i);
    }
    for (int j=0;j<m;j++){
        bool tmp1=0;
        for (int i=0;i<n;i++) if (matrix[i][j] == '#') tmp1=1;
        if (!tmp1) tmpy.push_back(j);
    }
    if ((tmpx.empty() && !tmpy.empty()) || (!tmpx.empty() && tmpy.empty())){
        printf("-1\n");
        return 0;
    }
    for (int i:tmpx) chk1[i]=1;
    for (int j:tmpy) chk2[j]=1;
    int ans=0;
    for (int i=0;i<n;i++){
        if (chk1[i]) continue;
        int chk = 0;
        for (int j=0;j<m;j++){
            if (chk==0){
                if (matrix[i][j]=='#') chk++;
            }
            else if (chk==1){
                if (matrix[i][j] == '.') chk++;
            }
            else if (chk==2){
                if (matrix[i][j] == '#') chk++;
            }
        }
        if (chk>2) ans=-1;
    }
    for (int j=0;j<m;j++){
        if (chk2[j]) continue;
        int chk = 0;
        for (int i=0;i<n;i++){
            if (chk==0){
                if (matrix[i][j]=='#') chk++;
            }
            else if (chk==1){
                if (matrix[i][j] == '.') chk++;
            }
            else if (chk==2){
                if (matrix[i][j] == '#') chk++;
            }
        }
        if (chk>2) ans=-1;
    }
    if (ans!=-1){
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (!visited[i][j] && matrix[i][j]=='#'){
                    dfs(i, j); ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}