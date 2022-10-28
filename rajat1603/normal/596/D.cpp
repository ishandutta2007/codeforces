#include "bits/stdc++.h"
using namespace std;
const int N = 2005;
int n , h;
int x[N];
double p;
int rhs[N];
int lhs[N];
double dp[N][N][2][2];
double solve(int s , int e , bool lft , bool rgt , int ls , int rs){//lgt 0 matlab left , lft 1 matlab right , rgt 0 matlab right , rgt1 matlab left
    if(s > e){
        return 0;
        return min(0 , rs - ls);
    }
    if(dp[s][e][lft][rgt] >= -1.0){
        return dp[s][e][lft][rgt];
    }
    double res = 0.0;
    res += p * (min(h , x[s] - ls) + solve(s + 1 , e , 0 , rgt , x[s] , rs));//falling left wala on left side
    res += (1.0 - p) * (min(x[rhs[s]] + h , rs) - x[s] + solve(rhs[s] + 1 , e , 1 , rgt , x[rhs[s]] + h , rs)); // falling left wala on right side
    res += (1.0 - p) * (min(h , rs - x[e]) + solve(s , e - 1 , lft , 0 , ls , x[e]));//right wala walling right side
    res += p * ((x[e] - max(x[lhs[e]] - h , ls)) + solve(s , lhs[e] - 1 , lft , 1 , ls , x[lhs[e]] - h));
    res /= 2.0;
    return dp[s][e][lft][rgt] = res;
}
int main(){
    cin >> n >> h >> p;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i ; j <= n ; ++j){
            dp[i][j][0][0] = -2;
            dp[i][j][1][0] = -2;
            dp[i][j][0][1] = -2;
            dp[i][j][1][1] = -2;
        }
    }
    sort(x + 1 , x + 1 + n);
    x[n + 1] = 1e9;
    x[0] = -1e9;
    for(int i = 1 ; i <= n ; ++i){
        rhs[i] = i;
        for(int j = i + 1 ; j <= n ; ++j){
            if(x[j] - x[j - 1] < h){
                rhs[i] = j;
            }
            else{
                break;
            }
        }
    }
    for(int i = n ; i >= 1 ; --i){
        lhs[i] = i;
        for(int j = i - 1 ; j >= 1 ; --j){
            if(x[j + 1] - x[j] < h){
                lhs[i] = j;
            }
            else{
                break;
            }
        }
    }
    cout << setprecision(12) << solve(1 , n , 0 , 0 , x[0] , x[n + 1]);
}