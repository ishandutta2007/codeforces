#include "bits/stdc++.h"
using namespace std;
long long n;
long long ans = 1;
int main(){
    cin >> n;
    for(int i = 2 ; 1LL * i * i <= n ; ++i){
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            ++cnt;
        }
        if(cnt){
            ans *= i;
        }
    }
    if(n > 1){
        ans *= n;
    }
    cout << ans;
}