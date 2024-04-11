#include "bits/stdc++.h"
using namespace std;
long long l , r , k;
long long cur = 1;
const long long ma = 1LL << 62;
bool ok = 1;
bool overflow(long long a , long long b){
    if(a > ma / b){
        return 1;
    }
    return 0;
}
int main(){
    cin >> l >> r >> k;
    while(cur <= r){
        if(cur >= l){
            ok = 0;
            cout << cur << " ";
        }
        if(overflow(cur , k)){
            break;
        }
        cur *= k;
    }
    if(ok){
        cout << -1;
    }
}