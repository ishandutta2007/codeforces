#include "bits/stdc++.h"
using namespace std;
const int N = 5e2 + 2;
const int dx[4] = {1 , -1 , 0 , 0};
const int dy[4] = {0 , 0 , -1 , 1};
int n , m , k;
char str[N][N];
bool visited[N][N];
int cnt;
int cur;
void dfs(int x , int y){
    if(visited[x][y]){
        return;
    }
    visited[x][y] = 1;
    ++cur;
    if(cur > cnt){
        str[x][y] = 'X';
    }
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(str[nx][ny] == '.'){
            dfs(nx , ny);
        }
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str[i] + 1);
        for(int j = 1 ; j <= m ; ++j){
            cnt += (str[i][j] == '.');
        }
    }
    cnt -= k;
    for(int i = 0 ; i <= m + 1 ; ++i){
        str[0][i] = '#';
        str[n + 1][i] = '#';
    }
    for(int i = 0 ; i <= n + 1 ; ++i){
        str[i][0] = '#';
        str[i][m + 1] = '#';
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(str[i][j] == '.'){
                dfs(i , j);
                i = n;
                break;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            printf("%c" , str[i][j]);
        }
        printf("\n");
    }
}