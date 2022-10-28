#include "bits/stdc++.h"
using namespace std;
const int N = 80;
const int inf = 1e6 + 6;
int n;
char str[N];
vector < int > v1;
vector < int > v2;
vector < int > v3;
int dp[N][N][N][2];
int cost(int r , int p1 , int p2 , int p3){
    int res = 0;
    for(int i = p1 ; i < v1.size() ; ++i){
        res += v1[i] < r;
    }
    for(int i = p2 ; i < v2.size() ; ++i){
        res += v2[i] < r;
    }
    for(int i = p3 ; i < v3.size() ; ++i){
        res += v3[i] < r;
    }
    return res;
}
int solve(int p1 , int p2 , int p3 , int pos , bool safe){
    if(pos > n){
        return 0;
    }
    if(dp[p1][p2][p3][safe] != -1){
        return dp[p1][p2][p3][safe];
    }
    int res = inf;
    if(p1 < v1.size()){
        res = min(res , solve(p1 + 1 , p2 , p3 , pos + 1 , 0) + cost(v1[p1] , p1 , p2 , p3));
    }
    if(safe && p2 < v2.size()){
        res = min(res , solve(p1 , p2 + 1 , p3 , pos + 1 , 1) + cost(v2[p2] , p1 , p2 , p3));
    }
    if(p3 < v3.size()){
        res = min(res , solve(p1 , p2 , p3 + 1 , pos + 1 , 1) + cost(v3[p3] , p1 , p2 , p3));
    }
    return dp[p1][p2][p3][safe] = res;
}
int main(){
    scanf("%d" , &n);
    scanf("%s" , str + 1);
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == 'V'){
            v1.emplace_back(i);
        }
        else if(str[i] == 'K'){
            v2.emplace_back(i);
        }
        else{
            v3.emplace_back(i);
        }
    }
    memset(dp , -1 , sizeof(dp));
    printf("%d\n" , solve(0 , 0 , 0 , 1 , 1));
}