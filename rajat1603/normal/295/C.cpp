#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int inf = 1e6 + 6;
const int mod = 1e9 + 7;
int n , k;
int arr[N];
int cnt1 , cnt2;
int pascal[N][N];
int dist[N][N][2];
int ways[N][N][2];
bool vis[N][N][2];
void solve(){
    for(int i = 0 ; i <= cnt1 ; ++i){
        for(int j = 0 ; j <= cnt2 ; ++j){
            for(int k = 0 ; k < 2 ; ++k){
                dist[i][j][k] = inf;
                ways[i][j][k] = 0;
                vis[i][j][k] = 0;
            }
        }
    }
    dist[cnt1][cnt2][0] = 0;
    ways[cnt1][cnt2][0] = 1;
    while(1){
        int me1;
        int me2;
        int sid;
        int dis = inf;
        for(int i = 0 ; i <= cnt1 ; ++i){
            for(int j = 0 ; j <= cnt2 ; ++j){
                for(int k = 0 ; k < 2 ; ++k){
                    if(!vis[i][j][k]){
                        if(dist[i][j][k] < dis){
                            dis = dist[i][j][k];
                            me1 = i;
                            me2 = j;
                            sid = k;
                        }
                    }
                }
            }
        }
        if(dis == inf){
            break;
        }
        vis[me1][me2][sid] = 1;
        int other1 = cnt1 - me1;
        int other2 = cnt2 - me2;
        int way = ways[me1][me2][sid];
        for(int i = 0 ; i <= min(k , me1) ; ++i){
            for(int j = !i ; j <= me2 && j + j + i <= k ; ++j){
                int nx = other1 + i;
                int ny = other2 + j;
                int ns = !sid;
                int nway = way;
                if(dist[nx][ny][ns] > dis + 1){
                    dist[nx][ny][ns] = dis + 1;
                    nway = (1LL * nway * pascal[me1][i]) % mod;
                    nway = (1LL * nway * pascal[me2][j]) % mod;
                    ways[nx][ny][ns] = nway;
                }
                else if(dist[nx][ny][ns] == dis + 1){
                    nway = (1LL * nway * pascal[me1][i]) % mod;
                    nway = (1LL * nway * pascal[me2][j]) % mod;
                    ways[nx][ny][ns] += nway;
                    if(ways[nx][ny][ns] >= mod){
                        ways[nx][ny][ns] -= mod;
                    }   
                }
            }
        }
    }
}
int main(){
    scanf("%d %d" , &n , &k);
    k /= 50;
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        arr[i] /= 50;
        cnt1 += (arr[i] == 1);
        cnt2 += (arr[i] != 1);
    }
    for(int i = 0 ; i < N ; ++i){
        pascal[i][0] = 1;
        for(int j = 1 ; j <= i ; ++j){
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % mod;
        }
    }
    solve();
    if(dist[cnt1][cnt2][1] >= inf){
        printf("-1\n0\n");
    }
    else{
        printf("%d\n%d\n" , dist[cnt1][cnt2][1] , ways[cnt1][cnt2][1]);
    }
}