#include "bits/stdc++.h"
using namespace std;
long long ans;
long long b , d , s;
int main(){
    cin >> b >> d >> s;
    ans = 5e18;
    for(int i = 0 ; i < 4 ; ++i){
        for(int j = i ; j < 4 ; ++j){
            long long aa = 0 , ba = 0 , ca = 0;
            if(i <= 0 && j > 0){
                ++aa;
            }
            if(i <= 1 && j > 1){
                ++ba;
            }
            if(i <= 2 && j > 2){
                ++ca;
            }
            if(aa >= b && ba >= d && ca >= s){
                ans = min(ans , j - i - b - d - s);
            }
        }
    }
    for(int i = 0 ; i < 4 ; ++i){
        for(int j = 0 ; j < 4 ; ++j){
            long long _b = 0, _d = 0 , _s = 0;
            if(i == 2){
                ++_s;
            }
            if(i == 1){
                ++_s;
                ++_d;
            }
            if(i == 0){
                ++_s;
                ++_d;
                ++_b;
            }
            if(j == 3){
                ++_s;
                ++_d;
                ++_b;
            }
            if(j == 2){
                ++_b;
                ++_d;
            }
            if(j == 1){
                ++_b;
            }
            _s = min(_s , s);
            _b = min(_b , b);
            _d = min(_d , d);
            long long x = max(s - _s , max(d - _d , b - _b));
            ans = min(ans , x * 3LL + 3 - i + j - s - b - d);
        }
    }
    cout << ans;
}