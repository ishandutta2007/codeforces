#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , k;
long long ans;
int bit[N];
void update(int idx){
    while(idx <= n){
        ++bit[idx];
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int query(int l , int r){
    if(l <= r){
        return query(r) - query(l - 1);
    }
    return 0;
}
int main(){
    scanf("%d %d" , &n , &k);
    ans = 1;
    int cur = 1;
    bool dir = 1;
    if(k + k > n){
        k = n - k;
        dir = -1;
    }
    for(int i = 1 ; i <= n ; ++i){
        int nxt;
        if(dir == 1){
            nxt = cur + k;
            if(nxt > n){
                nxt -= n;
            }
            if(cur <= nxt){
                ans += query(cur + 1 , nxt - 1);
            }
            else{
                ans += query(cur + 1 , n);
                ans += query(1 , nxt - 1);
            }
        }
        else{
            nxt = cur - k;
            if(nxt < 0){
                nxt += n;
            }
            if(nxt < cur){
                ans += query(nxt + 1 , cur - 1);
            }
            else{
                ans += query(nxt + 1 , n);
                ans += query(1 , cur - 1);
            }
        }
        ++ans;
        update(cur);
        update(nxt);
        cur = nxt;
        printf("%lld%c" , ans , " \n"[i == n]);
    }
}