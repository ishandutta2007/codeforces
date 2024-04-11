#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
long long l , r;
long long a[N];
long long b[N];
pair < long long , int > c[N];
int main(){
    scanf("%d" , &n);
    scanf("%lld %lld" , &l , &r);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , a + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , &c[i].first);
        c[i].second = i;
    }
    sort(c + 1 , c + 1 + n);
    long long last = -1LL << 60;
    for(int i = 1 ; i <= n ; ++i){
        int idx = c[i].second;
        b[idx] = last + a[idx] + 1;
        b[idx] = max(b[idx] , l);
        if(b[idx] > r){
            printf("-1\n");
            return 0;
        }
        last = max(last , b[idx] - a[idx]);
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%lld%c" , b[i] , " \n"[i == n]);
    }
}