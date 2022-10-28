#include "bits/stdc++.h"
using namespace std;
const int N = 755;
const int M = 2e5 + 5;
int n , m;
int arr[N];
pair < long long , int > que[M];
int ans[M];
int solve2(long long val){
    long long sum = val;
    priority_queue < int > pq;
    while(!pq.empty()){
        pq.pop();
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        sum += arr[i];
        pq.push(-arr[i]);
        while(sum < 0){
            sum += pq.top();
            pq.pop();
            ++ans;
        }
    }
    return ans;
}
int solve(int idx){
    if(ans[que[idx].second] != -1){
        return ans[que[idx].second];
    }
    return ans[que[idx].second] = solve2(que[idx].first);
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%lld" , &que[i].first);
        que[i].second = i;
        ans[i] = -1;
    }
    sort(que + 1 , que + 1 + m);
    for(int i = 1 ; i <= m ;){
        ans[que[i].second] = solve(i);
        if(solve(m) == solve(i)){
            for(int j = i + 1 ; j <= m ; ++j){
                ans[que[j].second] = solve(i);
            }
            i = m + 1;
        }
        else{
            int l = i + 1;
            int r = m;
            while(l < r){
                int mid = l + r >> 1;
                if(solve(mid) == solve(i)){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            for(int j = i + 1 ; j < l ; ++j){
                ans[que[j].second] = solve(i);
            }
            i = l;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        printf("%d\n" , ans[i]);
    }
}