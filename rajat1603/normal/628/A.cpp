#include "bits/stdc++.h"
using namespace std;
int n , b , p;
int cnt = 0;
int ans2;
int main(){
    cin >> n >> b >> p;
    ans2 = n * p;
    while(n > 1){
        int tmp = 1;
        while(tmp + tmp <= n){
            tmp += tmp;
        }
        cnt += tmp >> 1;
        n = (tmp >> 1) + (n - tmp);
    }
    cout << cnt * (b + b + 1) << " " << ans2;
}