#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int r , s , p;
double dp[N][N][N];
bool calc[N][N][N] = {0};
double ansr = 0.0 , anss = 0.0 , ansp = 0.0;
double solve(int rr , int ss , int pp){
    if(!((rr ^ r) | (ss ^ s) | (pp ^ p))){
        return 1.0;
    }
    if(rr > r || ss > s || pp > p){
        return 0.0;
    }
    if(calc[rr][ss][pp]){
        return dp[rr][ss][pp];
    }
    double a = solve(rr , ss + 1 , pp);
    double b = solve(rr + 1 , ss , pp);
    double c = solve(rr , ss , pp + 1);
    double x = 1.0 * (rr * (ss + 1)) / (rr * (ss + 1) + rr * pp + (ss + 1) * pp);
    double y = 1.0 * ((rr + 1) * pp) / ((rr + 1) * ss + (rr + 1) * pp + ss * pp);
    double z = 1.0 * (ss * (pp + 1)) / (rr * ss + rr * (pp + 1) + (pp + 1) * ss);
    if(rr == 0){
        x = 0;
    }
    if(pp == 0){
        y = 0;
    }
    if(ss == 0){
        z = 0;
    }
    calc[rr][ss][pp] = 1;
    return dp[rr][ss][pp] = a * x + b * y + c * z;
}
int main(){
    cin >> r >> s >> p;
    for(int i = 1 ; i <= r ; ++i){
        ansr += solve(i , 0 , 0);
    }
    for(int i = 1 ; i <= s ; ++i){
        anss += solve(0 , i , 0);
    }
    for(int i = 1 ; i <= p ; ++i){
        ansp += solve(0 , 0 , i);
    }
    printf("%.9lf %.9lf %.9lf" , ansr , anss , ansp);
}