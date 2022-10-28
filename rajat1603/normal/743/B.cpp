#include "bits/stdc++.h"
using namespace std;
int n;
long long k;
void solve(long long l , long long r , long long k){
    long long x = r + 1 >> 1;
    if(k < x){
        solve(l - 1 , r >> 1 , k);
        return;
    }
    if(x == k){
        printf("%lld\n" , l);
        exit(0);
    }
    solve(l - 1 , r >> 1 , k - x);
}
int main(){
    cin >> n >> k;
    solve(n , (1LL << n) - 1 , k);
}