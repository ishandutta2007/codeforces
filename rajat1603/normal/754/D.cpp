#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , k;
pair < pair < int , int > , int > arr[N];
int solve(int val){
    priority_queue < int > pq;
    int ans = 0;
    int idx;
    for(int i = 1 ; i <= n ; ++i){
        pq.push(-arr[i].first.second);
        while(pq.size() > k){
            pq.pop();
        }
        if(pq.size() == k){
            ans = max(ans , -pq.top() - arr[i].first.first + 1);
            if(ans == val){
                idx = i;
                break;
            }
        }
    }
    if(val >= 0){
        printf("%d\n" , ans);
        for(int i = 1 ; i <= idx ; ++i){
            swap(arr[i].first.first , arr[i].first.second);
        }
        sort(arr + 1 , arr + 1 + idx);
        reverse(arr + 1 , arr + 1 + idx);
        for(int i = 1 ; i <= k ; ++i){
            printf("%d%c" , arr[i].second , " \n"[i == k]);
        }
    }
    return ans;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first.first , &arr[i].first.second);
        arr[i].second = i;
    }
    sort(arr + 1 , arr + 1 + n);
    solve(solve(-1));
}