#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , p;
int l[N];
int r[N];
double ans = 0.0;
double get(int i , int j){
    int rr = r[i] / p;
    int ll = (l[i] - 1) / p;
    double z = rr - ll;
    z /= r[i] - l[i] + 1;
    int rrr = r[j] / p;
    int lll = (l[j] - 1) / p;
    double zz = rrr - lll;
    zz /= r[j] - l[j] + 1;
    return z + zz - z * zz;
}
int main(){
    scanf("%d %d" , &n , &p);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , l + i , r + i);
    }
    for(int i = 1 ; i < n ; ++i){
        ans += get(i , i + 1) * 2000.0;
    }
    ans += get(1 , n) * 2000.0;
    printf("%.9lf\n" , ans);
}