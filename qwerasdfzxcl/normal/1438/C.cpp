#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<pair<int, int>> adj1[101][101];
vector<pair<int, int>> adj2[101][101];
int matrix[101][101]={0};
int ans[101][101]={0};
bool visited[101][101]={0};

void dfs(int sx, int sy, int a){
    if (visited[sx][sy]) return;
    visited[sx][sy]=1;
    ans[sx][sy]=matrix[sx][sy]+a;
    for (auto &x:adj1[sx][sy]){
        dfs(x.first, x.second, (a+1)%2);
    }
    for (auto &x:adj2[sx][sy]){
        dfs(x.first, x.second, a);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                scanf("%d", &matrix[i][j]);
                if (i!=0){
                    if (matrix[i][j]==matrix[i-1][j]){
                        adj1[i][j].push_back(make_pair(i-1, j));
                        adj1[i-1][j].push_back(make_pair(i, j));
                    }
                    else if (abs(matrix[i][j]-matrix[i-1][j])==1){
                        adj2[i][j].push_back(make_pair(i-1, j));
                        adj2[i-1][j].push_back(make_pair(i, j));
                    }
                }
                if (j!=0){
                    if (matrix[i][j]==matrix[i][j-1]){
                        adj1[i][j].push_back(make_pair(i, j-1));
                        adj1[i][j-1].push_back(make_pair(i, j));
                    }
                    else if (abs(matrix[i][j]-matrix[i][j-1])==1){
                        adj2[i][j].push_back(make_pair(i, j-1));
                        adj2[i][j-1].push_back(make_pair(i, j));
                    }
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) dfs(i, j, 0);
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) printf("%d ", ans[i][j]);
            printf("\n");
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                adj1[i][j].clear();
                adj2[i][j].clear();
                matrix[i][j]=0;
                ans[i][j]=0;
                visited[i][j]=0;
            }
        }
    }
    return 0;
}