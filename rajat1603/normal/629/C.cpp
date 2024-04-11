#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int MAX = 2005;
const int ofset = 2001;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int n , m;
string str;
int sum = 0;
int mn = N;
int dp1[MAX][MAX];
int dp2[MAX + ofset][MAX];
int solve2(int sm , int pos);
int solve1(int sm , int pos){
    if(sm < 0){
        return 0;
    }
    if(!pos){
        return (sm + mn >= 0) && (!(sm + sum));
    }
    if(dp1[sm][pos] != -1){
        return dp1[sm][pos];
    }
    int res = 0;
    if(sm + mn >= 0){
        res = solve2(sm + sum , pos);
    }
    res = add(res , solve1(sm + 1 , pos - 1));
    res = add(res , solve1(sm - 1 , pos - 1));
    return dp1[sm][pos] = res;
}
int solve2(int sm , int pos){
    if(sm < 0){
        return 0;
    }
    if(!pos){
        return !sm;
    }
    if(dp2[sm - sum + ofset][pos] != -1){
        return dp2[sm - sum + ofset][pos];
    }
    return dp2[sm - sum + ofset][pos] = add(solve2(sm + 1 , pos - 1) , solve2(sm - 1 , pos - 1));
}
int main(){
    cin >> n >> m;
    cin >> str;
    memset(dp1 , -1 , sizeof(dp1));
    memset(dp2 , -1 , sizeof(dp2));
    for(char c : str){
        sum += (c == '(') ? 1 : -1;
        mn = min(mn , sum);
    }
    cout << solve1(0 , n - m);
}