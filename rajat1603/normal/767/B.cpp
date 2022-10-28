#include "bits/stdc++.h"
using namespace std;
long long ts , te , t;
int n;
long long when;
map < long long , int > mp;
long long mx , ans;
void check(long long s , long long l){
    if(s >= 0 && s < te){
        long long os = s;
        l = max(l , ts);
        long long wait = max(0LL , l - s);
        s = max(s , l);
        if(s + t <= te && s < te){
            if(wait < mx){
                mx = wait;
                ans = os;
            }
        }
    }
}
int main(){
    scanf("%lld %lld %lld" , &ts , &te , &t);
    scanf("%d" , &n);
    if(n == 0){
        printf("%lld\n" , ts);
        return 0;
    }
    mp.clear();
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , &when);
        ++mp[when];
    }
    mx = 1LL << 60;
    ans = 0;
    long long last = 0;
    for(auto it : mp){
        if(last < it.first){
            check(last , last);
        }
        if(ts < it.first){
            check(ts , last);
        }
        check(it.first - 1 , last);
        last = max(last , ts);
        last = max(last , it.first);
        last += t * it.second;
        check(it.first , last);
    }
    check(last , last);
    printf("%lld\n" , ans);
}