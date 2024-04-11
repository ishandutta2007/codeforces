#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n;
int m[2];
int arr[2][N];
queue < pair < bool , int > > q;
int cnt[2][N];
int dis[2][N];
int get(int idx , int move){
    idx -= move;
    if(idx < 1){
        idx += n;
    }
    return idx;
}
int main(){
    scanf("%d" , &n);
    for(int i = 0 ; i < 2 ; ++i){
        scanf("%d" , m + i);
        for(int j = 1 ; j <= m[i] ; ++j){
            scanf("%d" , &arr[i][j]);
        }
    }
    memset(dis , -1 , sizeof(dis));
    dis[0][1] = 0;
    dis[1][1] = 0;
    q.push({0 , 1});
    q.push({1 , 1});
    while(!q.empty()){
        int pos = q.front().second;
        bool who = q.front().first;
        int state = dis[who][pos];
        q.pop();
        for(int i = 1 ; i <= m[who ^ 1] ; ++i){
            int val = arr[who ^ 1][i];
            int idx = pos - val;
            idx += (idx < 1) * n;
            if(!state && dis[who ^ 1][idx] == -1){
                dis[who ^ 1][idx] = 1;
                q.push({who ^ 1 , idx});
            }
            else{
                ++cnt[who ^ 1][idx];
                if(cnt[who ^ 1][idx] == m[who ^ 1] && dis[who ^ 1][idx] == -1){
                    dis[who ^ 1][idx] = 0;
                    q.push({who ^ 1 , idx});
                }
            }
        }
    }
    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 2 ; j <= n ; ++j){
            if(dis[i][j] == 1){
                printf("Win");
            }
            else if(dis[i][j] == 0){
                printf("Lose");
            }
            else{
                printf("Loop");
            }
            printf("%c" , " \n"[j == n]);
        }
    }
}