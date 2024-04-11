#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n , m;
int sum[N][N];
int ans = 0;
vector < int > arr(3);
int getsum(int x1 , int y1 , int x2 , int y2){
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    memset(sum , 0 , sizeof(sum));
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            cin >> sum[i][j];
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for(int i = 0 ; i < 3 ; ++i){
        cin >> arr[i];
    }
    sort(arr.begin() , arr.end());
    for(int i = 1 ; i < m - 1 ; ++i){
        for(int j = i + 1 ; j < m ; ++j){
            vector < int > temp = {getsum(1 , 1 , n , i) , getsum(1 , i + 1 , n , j) , getsum(1 , j + 1 , n , m)};
            sort(temp.begin() , temp.end());
            ans += (temp == arr);
        }
    }
    for(int i = 1 ; i < n - 1 ; ++i){
        for(int j = i + 1 ; j < n ; ++j){
            vector < int > temp = {getsum(1 , 1 , i , m) , getsum(i + 1 , 1 , j , m) , getsum(j + 1 , 1 , n , m)};
            sort(temp.begin() , temp.end());
            ans += (temp == arr);
        }
    }
    cout << ans;
}