#include "bits/stdc++.h"
using namespace std;
const double pi = 3.1415926535897932384626;
const int N = 1e5 + 5;
const long long inf = 1e13 + 13;
int n;
int r[N];
int h[N];
pair < long long , int > inp[N];
long long arr[N];
long long bit[N];
int cur = 0;
void update(int idx , long long val){
    while(idx <= cur){
        bit[idx] = max(bit[idx] , val);
        idx += idx & -idx;
    }
}
long long query(int idx){
    long long res = 0;
    while(idx){
        res = max(res , bit[idx]);
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , r + i , h + i);
        inp[i] = make_pair(1LL * r[i] * r[i] * h[i] , i);
    }
    inp[0].first = -1;
    sort(inp + 1 , inp + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        cur += (inp[i].first != inp[i - 1].first);
        arr[inp[i].second] = cur;
    }
    for(int i = 1 ; i <= n ; ++i){
        long long tmp = query(arr[i] - 1);
        update(arr[i] , tmp + 1LL * r[i] * r[i] * h[i]);
    }
    printf("%.9lf\n" , query(cur) * pi);
}