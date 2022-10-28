#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n , k;
char str[N][N];
int comp[N][N];
int sz[N * N];
int num;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
void dfs(int x , int y){
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(str[nx][ny] == '.' && comp[nx][ny] == -1){
            comp[nx][ny] = num;
            ++sz[num];
            dfs(nx , ny);
        }
    }
}
int ans;
int lst[N * N];
int timer;
int tmp;
void add(int row , int col){
    if(str[row][col] == '.'){
        if(lst[comp[row][col]] != timer){
            tmp += sz[comp[row][col]];
            lst[comp[row][col]] = timer;
        }
    }
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , str[i] + 1);
    }
    for(int i = 0 ; i <= n + 1 ; ++i){
        str[i][0] = 'x';
        str[i][n + 1] = 'x';
    }
    for(int i = 0 ; i <= n + 1 ; ++i){
        str[0][i] = 'x';
        str[n + 1][i] = 'x';
    }
    num = 0;
    memset(comp , -1 , sizeof(comp));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(str[i][j] == '.' && comp[i][j] == -1){
                ++num;
                comp[i][j] = num;
                sz[num] = 1;
                dfs(i , j);
            }
        }
    }
    ans = 0;
    memset(lst , 0 , sizeof(lst));
    timer = 0;
    int top = 1;
    int bot = k;
    while(bot <= n){
        int lft = 1;
        int rgt = k;
        for(int i = top ; i <= bot ; ++i){
            for(int j = lft ; j <= rgt ; ++j){
                if(str[i][j] == '.'){
                    --sz[comp[i][j]];
                }
            }
        }
        while(rgt <= n){
            tmp = k * k;
            ++timer;
            for(int i = top ; i <= bot ; ++i){
                add(i , lft - 1);
                add(i , rgt + 1);
            }
            for(int i = lft ; i <= rgt ; ++i){
                add(top - 1 , i);
                add(bot + 1 , i);
            }
            ans = max(ans , tmp);
            for(int i = top ; i <= bot ; ++i){
                if(str[i][lft] == '.'){
                    ++sz[comp[i][lft]];
                }
                if(str[i][rgt + 1] == '.'){
                    --sz[comp[i][rgt + 1]];
                }
            }
            ++lft;
            ++rgt;
        }
        for(int i = top ; i <= bot ; ++i){
            for(int j = lft ; j <= rgt ; ++j){
                if(str[i][j] == '.'){
                    ++sz[comp[i][j]];
                }
            }
        }
        ++top;
        ++bot;
    }
    printf("%d\n" , ans);
}