#include "bits/stdc++.h"
using namespace std;
const int N = 6e4 + 4;
int n;
int x[N];
int v[N];
double check(double place){
    double res = 0;
    for(int i = 1 ; i <= n ; ++i){
        res = max(res , max(x[i] - place , place - x[i]) / v[i]);
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , x + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , v + i);
    }
    double l = 0.9;
    double r = 1e9 + 9;
    for(int i = 0 ; i < 100 ; ++i){
        double mid1 = cbrt(l * l * r);
        double mid2 = cbrt(l * r * r);
        if(check(mid1) < check(mid2)){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    printf("%.9lf" , check(l));
}