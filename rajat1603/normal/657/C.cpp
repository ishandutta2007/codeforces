#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k , b , c;
int arr[N];
long long ans;
int tmp[N];
int val[N];
void solve(int r){
    for(int i = 1 ; i <= n ; ++i){
        tmp[i] = (((r - arr[i]) % 5) + 5) % 5;
        val[i] = arr[i] + tmp[i];
    }
    priority_queue < long long > pq;
    while(!pq.empty()){
        pq.pop();
    }
    long long sum = 0;
    for(int i = 1 ; i <= n ; ++i){
        while(pq.size() >= k){
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() + 1 >= k){
            ans = min(ans , sum + 1LL * (k - 1) * b * ((val[i] < 0 ? val[i] - 4 : val[i]) / 5LL) + tmp[i] * c);
        }
        long long cst = 1LL * tmp[i] * c - 1LL * b * ((val[i] < 0 ? val[i] - 4 : val[i]) / 5LL);
        pq.push(cst);
        sum += cst;
    }
}
int main(){
    scanf("%d %d %d %d" , &n , &k , &b , &c);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    ans = 1LL << 60;
    b = min(b , c * 5);
    for(int i = 0 ; i < 5 ; ++i){
        solve(i);
    }
    printf("%lld\n" , ans);
}