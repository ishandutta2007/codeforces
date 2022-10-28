#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int LN = 10;
int n , m;
char str[3];
int sum[N][N];
short val[N][N];
int get(int x1 , int y1 , int x2 , int y2){
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int find(int i , int j){
    if(get(i , j , i , j)){
        return 0;
    }
    int l = 1;
    int r = min(n - i , m - j) + 1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(get(i , j , i + mid - 1 , j + mid - 1)){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    return l;
}
short st[LN][LN][N][N];
int logtable[N];
void build(){
    logtable[1] = 0;
    for(int i = 2 ; i < N ; ++i){
        logtable[i] = logtable[i >> 1] + 1;
    }
    for(int x = 0 ; x < LN ; ++x){
        for(int y = 0 ; y < LN ; ++y){
            for(int i = 1 ; i + (1 << x) - 1 <= n ; ++i){
                for(int j = 1 ; j + (1 << y) - 1 <= m ; ++j){
                    if(x + y == 0){
                        st[x][y][i][j] = val[i][j];
                    }
                    else if(x == 0){
                        st[x][y][i][j] = max(st[x][y - 1][i][j] , st[x][y - 1][i][j + (1 << (y - 1))]);
                    }
                    else if(y == 0){
                        st[x][y][i][j] = max(st[x - 1][y][i][j] , st[x - 1][y][i + (1 << (x - 1))][j]);
                    }
                    else{
                        st[x][y][i][j] = max(st[x][y - 1][i][j] , st[x][y - 1][i][j + (1 << (y - 1))]);
                    }
//                    cout << i << " " << j << " " << (1 << x) << " " << (1 << y) << " " << st[x][y][i][j] << endl;
                }
            }
        }
    }
}
short getmax(int x1 , int y1 , int x2 , int y2){
    int lrow = logtable[x2 - x1 + 1];
    int lcol = logtable[y2 - y1 + 1];
    return max(max(st[lrow][lcol][x1][y1] , st[lrow][lcol][x1][y2 - (1 << lcol) + 1]) , max(st[lrow][lcol][x2 - (1 << lrow) + 1][y1] , st[lrow][lcol][x2 - (1 << lrow) + 1][y2 - (1 << lcol) + 1]));
    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << lrow << " " << lcol << " " << ret << endl;
}
void solve(int x1 , int y1 , int x2 , int y2){
    int l = 1;
    int r = min(x2 - x1 + 1 , y2 - y1 + 1);
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(getmax(x1 , y1 , x2 - mid + 1 , y2 - mid + 1) >= mid){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%d\n" , l);
}
int main(){
    scanf("%d %d" , &n , &m);
    memset(sum , 0 , sizeof(sum));
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%s" , str);
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (str[0] == '0');
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            val[i][j] = find(i , j);
        }
    }
    build();
    int q;
    scanf("%d" , &q);
    while(q--){
        int x1 , y1 , x2 , y2;
        scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2);
        if(get(x1 , y1 , x2 , y2) == (x2 - x1 + 1) * (y2 - y1 + 1)){
            printf("0\n");
        }
        else{
            solve(x1 , y1 , x2 , y2);
        }
    }
}