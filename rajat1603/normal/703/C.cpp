#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n , w , v , u;
pair < int , int > arr[N];
double ans;
int main(){
    scanf("%d %d %d %d" , &n , &w , &v , &u);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
    }
    bool ok = 1;
    for(int i = 1 ; i <= n ; ++i){
        double tm = 1.0 * arr[i].second / u;
        double x = arr[i].first - tm * v;
        if(x < 0){
            ok = 0;
            break;
        }
    }
    if(ok){
        printf("%.6lf\n" , 1.0 * w / u);
        return 0;
    }
    sort(arr + 1 , arr + 1 + n , [](pair < int , int > a , pair < int , int > b){
        return make_pair(a.second , a.first) < make_pair(b.second , b.first);
    });
    ans = 0.0;
    ans = max(1.0 * arr[1].second / u , 1.0 * arr[1].first / v);
    int cury = arr[1].second;
    for(int i = 2 ; i <= n ; ++i){
        double tm = ans + (1.0 * (arr[i].second - cury) / u);
        double tx = arr[i].first - tm * v;
        if(tx > 0){
            tm += tx / v;
        }
        ans = tm;
        cury = arr[i].second;
    }
    ans += 1.0 * (w - cury) / u;
    printf("%.6lf\n" , ans);
}