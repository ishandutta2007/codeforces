#include "bits/stdc++.h"
using namespace std;
const int N = 335;
const int M = 7;
const int NN = 32;
int n;
int arr[N];
bool visited[N][N][NN][M][8];
const int dx[8] = {1 , 1 , 0 , -1 , -1 , -1 , 0 , 1};
const int dy[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};
int prv(int x){
    return (x + 7) % 8;
}
int nxt(int x){
    return (x + 1) % 8;
}
void dfs(int x , int y , int level , int len , int dir){
    if(level > n){
        return;
    }
    if(visited[x][y][level][len][dir]){
        return;
    }
    visited[x][y][level][len][dir] = 1;
    if(len < arr[level]){
        dfs(x + dx[dir] , y + dy[dir] , level , len + 1 , dir);
    }
    else{
        dfs(x + dx[prv(dir)] , y + dy[prv(dir)] , level + 1 , 1 , prv(dir));
        dfs(x + dx[nxt(dir)] , y + dy[nxt(dir)] , level + 1 , 1 , nxt(dir));
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    int x = 155;
    int y = 155;
    dfs(x , y , 1 , 1 , 0);
    int ans = 0;
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            for(int k = 1 ; k <= n ; ++k){
                for(int l = 1 ; l <= 5 ; ++l){
                    for(int m = 0 ; m < 8 ; ++m){
                        if(visited[i][j][k][l][m]){
                            ++ans;
                            k = n + 1;
                            l = 6;
                            m = 8;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n" , ans);
}

/*
7 0 1
6 x 2
5 4 3

bool visited[N][N][NN][M][8];
*/