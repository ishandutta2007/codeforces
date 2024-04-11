#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
double tmp[N];
double sum[N];
double l , r;
double ans = 1e10;
double check(double val){
    sum[0] = 0;
    double mn = 0;
    double mx = 0;
    double ret = -1e10;
    for(int i = 1 ; i <= n ; ++i){
        tmp[i] = arr[i];
        tmp[i] -= val;
        sum[i] = sum[i - 1] + tmp[i];
        ret = max(ret , max(sum[i] - mn , mx - sum[i]));
        mx = max(mx , sum[i]);
        mn = min(mn , sum[i]);
    }
    return ret;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    r = 1e6;
    l = 0;
    ans = check(0);
    for(int i = 1 ; i <= 100 ; ++i){
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        double x = check(mid1);
        double y = check(mid2);
        ans = min(ans , min(x , y));
        if(x < y){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    l = -1e6;
    r = 0;
    for(int i = 1 ; i <= 100 ; ++i){
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;
        double x = check(mid1);
        double y = check(mid2);
        ans = min(ans , min(x , y));
        if(x < y){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    printf("%.6lf" , ans);
}