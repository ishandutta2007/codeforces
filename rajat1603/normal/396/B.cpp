#include "bits/stdc++.h"
using namespace std;
bool prime(int n){
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int t;
int n;
long long num , den;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(prime(n + 1)){
            num = n - 1;
            den = n + n + 2;
        }
        else{
            int last;
            for(int i = n ; ; --i){
                if(prime(i)){
                    last = i - 1;
                    break;
                }
            }
            int next;
            for(int i = n + 1 ; ; ++i){
                if(prime(i)){
                    next = i;
                    break;
                }
            }
            num = (last + 1LL) * (next * 1LL) - 2LL * next + 2LL * (n - last + 0LL);
            den = 2LL * (last + 1LL) * next;
        }
        long long g = __gcd(num , den);
        printf("%lld/%lld\n" , num , den);
    }
}