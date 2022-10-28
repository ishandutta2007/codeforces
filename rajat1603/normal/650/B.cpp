#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , a , b , t;
int curt;
int orit;
char arr[N];
int ans = 0;
int curans;
int sum[N];
int r;
int main(){
    scanf("%d %d %d %d" , &n , &a , &b , &t);
    orit = t;
    scanf("%s" , arr + 1);
    sum[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        sum[i] = sum[i - 1] + (arr[i] == 'w');
    }
    --t;
    t -= sum[1] * b;
    if(t < 0){
        printf("0\n");
        return 0;
    }
    ans = 1;
    curt = t;
    curans = 1;
    for(int i = n ; i >= 2 ; --i){
        int cst = a + 1 + (b * int(arr[i] == 'w'));
        if(cst > curt){
            break;
        }
        r = i;
        curt -= cst;
        ++curans;
    }
    ans = max(ans , curans);
    for(int i = 2 ; i < n ; ++i){
        long long cst = 2LL * a * (i - 1LL) + 1LL * (sum[i] - sum[1]) * b + i - 1LL;
        while(((cst > curt) || (r <= i)) && (r <= n)){
            curt += a + 1 + (b * int(arr[r] == 'w'));
            ++r;
            --curans;
        }
        ++curans;
        if(curt >= cst){
            ans = max(ans , curans);
        }
    }
    curt = t;
    curans = 1;
    r = 1;
    for(int i = 2 ; i <= n ; ++i){
        int cst = a + 1 + (b * int(arr[i] == 'w'));
        if(cst > curt){
            break;
        }
        r = i;
        curt -= cst;
        ++curans;
    }
    ans = max(ans , curans);
    for(int i = n ; i >= 2 ; --i){
        long long cst = 2LL * a * (n + 1LL - i) + 1LL * (sum[n] - sum[i - 1]) * b + (n - i + 1LL);
        while(((cst > curt) || (r >= i)) && (r >= 2)){
            curt += a + 1 + (b * int(arr[r] == 'w'));
            --r;
            --curans;
        }
        ++curans;
        if(curt >= cst){
            ans = max(ans , curans);
        }
    }
    printf("%d\n" , ans);
}