#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
pair < long long , long long > arr[N];
priority_queue < long long > pq;
int ans;
pair < long long , long long > limak;
int pos;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld %lld" , &arr[i].first , &arr[i].second);
    }
    limak = arr[1];
    sort(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] == limak){
            pos = i;
        }
    }
    for(int i = pos ; i < n ; ++i){
        swap(arr[i] , arr[i + 1]);
    }
    for(int i = n ; i >= 1 ; --i){
        if(arr[i].first > limak.first){
            pq.push(arr[i].first - arr[i].second);
            pos = i;
        }
    }
    --pos;
    ans = pq.size() + 1;
    while(!pq.empty()){
        long long req = -pq.top();
        pq.pop();
        limak.first -= req + 1;
        if(limak.first < 0){
            break;
        }
        while(pos >= 1 && arr[pos].first > limak.first){
            pq.push(arr[pos].first - arr[pos].second);
            --pos;
        }
        ans = min(ans , 1 + int(pq.size()));
    }
    printf("%d\n" , ans);
}