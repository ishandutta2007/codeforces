#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
int n , m;
char arr[N][N];
int parent[N * N];
int siz[N * N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
int find(int i , int j){
    if(min(i , j) < 1 || i > n || j > m){
        return -1;
    }
    return find((i - 1) * m + j);
}
void join(int a , int b , int c , int d){
    if(arr[a][b] == '.' && arr[c][d] == '.'){
        if(find(a , b) == find(c , d)){
            return;
        }
        siz[find(c , d)] += siz[find(a , b)];
        parent[find(a , b)] = find(c , d);
    }
}
int main(){
    srand(time(NULL));
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , arr[i] + 1);
    }
    for(int i = n * m ; i >= 1 ; --i){
        parent[i] = i;
        siz[i] = 1;
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            for(int k = 0 ; k < 2 ; ++k){
                join(i , j , i + dx[k] , j + dy[k]);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(arr[i][j] == '.'){
                putchar('.');
            }
            else{
                int ans = 1;
                for(int k = 0 ; k < 4 ; ++k){
                    if(find(i + dx[k] , j + dy[k]) == -1 || arr[i + dx[k]][j + dy[k]] != '.'){
                        continue;
                    }
                    bool ok = 1;
                    for(int l = 0 ; l < k ; ++l){
                        if(find(i + dx[k] , j + dy[k]) == find(i + dx[l] , j + dy[l])){
                            ok = 0;
                            break;
                        }
                    }
                    if(ok){
                        //cout << i << " " << j << " " << k << " ";
                        ans += siz[find(i + dx[k] , j + dy[k])];
                    }
                }
                ans %= 10;
                putchar(ans + '0');
            }
        }
        putchar('\n');
    }
}