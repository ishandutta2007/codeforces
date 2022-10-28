#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
int n , m , k;
string str[N];
int visited[N][N];
int ans[N * N];
int val[N][N];
int val2[N][N];
int x , y;
int iter;
void bfs(int i , int j){
    if(visited[i][j] != -1){
        return;
    }
    ++iter;
    queue < pair < int , int > > q;
    q.push(make_pair(i , j));
    visited[i][j] = iter;
    while(!q.empty()){
        auto node = q.front();
        if(val2[node.first][node.second] != iter){
            ans[iter] += val[node.first][node.second];
        }
        q.pop();
        val2[node.first][node.second] = iter;
        for(int k = 0 ; k < 4 ; ++k){
            int nx = node.first + dx[k];
            int ny = node.second + dy[k];
            if(visited[nx][ny] != -1){
                continue;
            }
            if(str[nx][ny] == '.'){
                visited[nx][ny] = iter;
                q.push(make_pair(nx , ny));
            }
        }
    }
}
int main(){
    memset(val2 , -1 , sizeof(val2));
    iter = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> str[i];
        str[i] = " " + str[i];
    }
    memset(val , 0 , sizeof(val));
    for(int i = 2 ; i < n ; ++i){
        for(int j = 2 ; j < m ; ++j){
            for(int k = 0 ; k < 4 ; ++k){
                val[i][j] += (str[i + dx[k]][j + dy[k]] == '*');
            }
        }
    }
    memset(visited , -1 , sizeof(visited));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(str[i][j] == '.'){
                bfs(i , j);
            }
        }
    }
    while(k--){
        cin >> x >> y;
        cout << ans[visited[x][y]] << endl;
    }
}