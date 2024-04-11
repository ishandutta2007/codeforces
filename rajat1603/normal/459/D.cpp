#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
map < int , int > cnt;
int arr[N];
int bit[N];
int l[N];
long long ans = 0;
int n;
inline int query(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx &= idx - 1;
    }
    return res;
}
inline void update(int idx){
    while(idx <= n){
        ++bit[idx];
        idx += idx & -idx;
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        cnt[arr[i]]++;
        l[i] = cnt[arr[i]];
    }
    cnt.clear();
    for(int i = n ; i >= 1 ; --i){
        ans += query(l[i] - 1);
        cnt[arr[i]]++;
        update(cnt[arr[i]]);
    }
    printf("%lld" , ans);
}