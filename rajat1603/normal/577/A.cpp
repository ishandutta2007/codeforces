#include "bits/stdc++.h"
using namespace std;
int n , x;
int ans = 0;
int main(){
    cin >> n >> x;
    for(int i = 1 ; i <= n ; ++i){
        if(x % i == 0){
            if(((x / i) <= n) && ((x / i) >= 1)){
                ++ans;
            }
        }
    }
    cout << ans;
}