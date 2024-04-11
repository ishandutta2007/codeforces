#include "bits/stdc++.h"
using namespace std;
int n;
long long l , r;
inline int log(long long r){
    if(r <= INT_MAX){
        return 31 - __builtin_clz(r);
    }
    else{
        r >>= 31;
        return 62 - __builtin_clz(r);
    }
}
long long solve(long long l , long long r){
    if(l == r){
        return l;
    }
    long long temp = 1LL << (log(r));
    if(temp <= l){
        return solve(l - temp , r - temp) + temp;
    }
    if(temp + temp - 1 <= r){
        return temp + temp - 1;
    }
    return temp - 1;
}
int main(){
    cin >> n;
    while(n--){
        cin >> l >> r;
        cout << solve(l , r) << endl;
    }
}