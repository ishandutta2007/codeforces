#include "bits/stdc++.h"
using namespace std;
unsigned long long a , b;
unsigned long long solve(unsigned long long a , unsigned long long b){
    if(a == 0){
        if(b == 0){
            return 0;
        }
        return -1ULL;
    }
    if(b == 0){
        if(a & 1){
            return -1ULL;
        }
        return (a >> 1);
    }
    if((a & 1) != (b & 1)){
        return -1ULL;
    }
    unsigned long long res = solve(a >> 1 , b >> 1);
    if(res == -1ULL){
        if(a & 1){
            return -1ULL;
        }
        res = solve((a >> 1) - 1 , b >> 1);
        if(res == -1ULL){
            return -1ULL;
        }
        return res + res + 1;
    }
    return res + res;
}
int main(){
    cin >> a >> b;
    if(solve(a , b) == -1ULL){
        cout << -1;
    }
    else{
        cout << solve(a , b) << " " << (b ^ solve(a , b));
    }
}