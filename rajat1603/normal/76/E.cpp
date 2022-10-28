#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int x[N];
int y[N];
long long ans = 0;
long long sum1[N];
long long sum2[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , x + i , y + i);
        sum1[i] = sum1[i - 1] + x[i];
        sum2[i] = sum2[i - 1] + y[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        ans += 1LL * (n - 1LL) * (x[i] * x[i]);
        ans += 1LL * (n - 1LL) * (y[i] * y[i]);
        ans -= 2LL * x[i] * sum1[i - 1];
        ans -= 2LL * y[i] * sum2[i - 1];
    }
    cout << ans;
}