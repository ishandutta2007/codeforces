#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
pair < pair < int , int > , int > arr[N];
vector < int > v;
long long bit[N];
void update(int idx , long long val){
    ++idx;
    while(idx < N){
        bit[idx] = max(bit[idx] , val);
        idx += idx & -idx;
    }
}
long long query(int idx){
    long long res = 0;
    ++idx;
    while(idx){
        res = max(res , bit[idx]);
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d %d" , &arr[i].first.second , &arr[i].first.first , &arr[i].second);
        v.emplace_back(arr[i].first.first);
        v.emplace_back(arr[i].first.second);
    }
    sort(arr + 1 , arr + 1 + n);
    sort(v.begin() , v.end());
    v.resize(unique(v.begin() , v.end()) - v.begin());
    for(int i = n ; i >= 1 ; --i){
        int a = arr[i].first.second;
        int b = arr[i].first.first;
        int a_idx = lower_bound(v.begin() , v.end() , a) - v.begin();
        update(a_idx , query(lower_bound(v.begin() , v.end() , b) - v.begin() - 1) + arr[i].second);
    }
    printf("%lld\n" , query(v.size() - 1));
}