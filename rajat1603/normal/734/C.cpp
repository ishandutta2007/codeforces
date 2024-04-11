#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m , k;
int x , s;
pair < int , int > arr1[N];
pair < int , int > arr2[N];
long long ans;
void solve(int n , int s){
    if(n <= 0){
        ans = 0;
    }
    else{
        auto it = lower_bound(arr1 + 1 , arr1 + 2 + m , make_pair(s + 1 , -1));
        --it;
        ans = min(ans , 1LL * n * it -> second);
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    scanf("%d %d" , &x , &s);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &arr1[i].second);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &arr1[i].first);
    }
    sort(arr1 + 1 , arr1 + 1 + m);
    for(int i = 2 ; i <= m ; ++i){
        arr1[i].second = min(arr1[i - 1].second , arr1[i].second);
    }
    arr1[m + 1] = make_pair(2e9 + 9 , x);
    arr1[0] = make_pair(0 , x);
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , &arr2[i].second);
    }
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , &arr2[i].first);
    }
    ans = 1LL * x * n;
    for(int i = 1 ; i <= k ; ++i){
        if(arr2[i].first <= s){
            solve(n - arr2[i].second , s - arr2[i].first);
        }
    }
    solve(n , s);
    printf("%lld\n" , ans);
}