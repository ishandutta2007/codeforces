#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 10;
const int K = N << 10;
long long a[K];
long long b[K];
int arr[N][N];
int n , m , k , p;
priority_queue < long long > pq;
long long ans = LLONG_MIN;
int main(){
    scanf("%d %d %d %d" , &n , &m , &k , &p);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%d" , &arr[i][j]);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        long long sum = 0;
        for(int j = 1 ; j <= m ; ++j){
            sum += arr[i][j];
        }
        pq.push(sum);
    }
    for(int i = 1 ; i <= k ; ++i){
        a[i] = pq.top();
        pq.pop();
        pq.push(a[i] - m * p);
        a[i] += a[i - 1];
    }
    while(!pq.empty()){
        pq.pop();
    }
    for(int i = 1 ; i <= m ; ++i){
        long long sum = 0;
        for(int j = 1 ; j <= n ; ++j){
            sum += arr[j][i];
        }
        pq.push(sum);
    }
    for(int i = 1 ; i <= k ; ++i){
        b[i] = pq.top();
        pq.pop();
        pq.push(b[i] - n * p);
        b[i] += b[i - 1];
    }
    for(int i = 0 ; i <= k ; ++i){
        ans = max(ans , a[i] + b[k - i] - 1LL * i * (k - i) * p);
    }
    cout << ans;
}