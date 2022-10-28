#include "bits/stdc++.h"
using namespace std;
long long n , l , r;
long long power(long long a , long long b){
    long long res = 1;
    while(b){
        if(b & 1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}
int main(){
    cin >> n >> l >> r;
    if(n == 1){
        cout << r - l + 1LL << endl;
    }
    else if(n == 2){
        cout << (r - l + 1LL) * (r - l) << endl;
    }
    else if(n > 25){
        cout << "0\n";
    }
    else{
        long long res = 0;
        for(long long denom = 1 ; ; ++denom){
            long long start = power(denom , n - 1);
            if(start > r){
                break;
            }
            long long ll = ((l + start - 1) / start) * start;
            long long rr = (r / start) * start;
            for(long long val = ll ; val <= rr ; val += start){
                long long a = val / start;
                for(long long x = denom + 1 ; a * power(x , n - 1) <= r ; ++x){
                    res += __gcd(x , denom) == 1;
                }
            }
        }
        res *= 2;
        cout << res << endl;
    }
}