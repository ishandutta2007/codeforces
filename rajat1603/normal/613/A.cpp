#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const double pi = 3.141592653589793238462643383279502884197;
const double eps = 1e-6;
int n;
int x , y;
int a[N] , b[N];
long long far = 0;
double near = 1e16;
double ans;
long long sqr(long long x){
    return x * x;
}
long long dist(int x , int y , int x2 , int y2){
    return sqr(x - x2) + sqr(y - y2);
}
double sqrr(double x){
    return x * x;
}
double solve(int x1 , int y1 , int x2 , int y2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dr = dist(x1 , y1 , x2 , y2);
    double D = 1LL * x1 * y2 - 1LL * x2 * y1;
    double x = D * dy / dr;
    double y = -D * dx / dr;
    if(x >= min(x1 , x2) && x <= max(x1 , x2)){
        return x * x + y * y;
    }
    return 1e16;
}
int main(){
    scanf("%d %d %d" , &n , &x , &y);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &a[i] , &b[i]);
        a[i] -= x;
        b[i] -= y;
        far = max(far , dist(0 , 0 , a[i] , b[i]));
        near = min(near , 1.0 * dist(0 , 0 , a[i] , b[i]));
    }
    for(int i = 1 ; i < n ; ++i){
        near = min(near , solve(a[i] , b[i] , a[i + 1] , b[i + 1]));
    }
    near = min(near , solve(a[n] , b[n] , a[1] , b[1]));
    ans = far - near;
    ans *= pi;
    printf("%.9lf\n" , ans);
}