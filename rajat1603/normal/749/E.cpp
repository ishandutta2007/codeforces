#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
double ans;
long long nc2;
long long bit1[N];
long long bit2[N];
void update(long long bit[] , int idx , int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx & -idx;
    }
}
long long query(long long bit[] , int idx){
    long long res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    ans = 0;
    nc2 = 1LL * n * (n + 1);
    for(int i = n ; i >= 1 ; --i){
        long long val1 = query(bit2 , n) - query(bit2 , arr[i]);
        long long val2 = query(bit2 , arr[i] - 1);
        int cnt2 = query(bit1 , arr[i] - 1);
        ans += 1.0 * (val1 * i + nc2 * cnt2 - val2 * i) / nc2;
        update(bit1 , arr[i] , 1);
        update(bit2 , arr[i] , n - i + 1);
    }
    printf("%.9lf\n" , ans);
}