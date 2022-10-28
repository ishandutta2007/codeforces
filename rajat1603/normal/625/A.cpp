#include "bits/stdc++.h"
using namespace std;
long long n , a , b , c;
int main(){
    cin >> n >> a >> b >> c;
    if(a <= b - c){
        cout << n / a;
    }
    else{
        n -= b;
        long long ans = 0;
        if(n >= b - c){
            ans = n / (b - c);
            n %= (b - c);
        }
        n += b;
        while(n >= b){
            ++ans;
            n -= b - c;
        }
        ans += n / a;
        cout << ans;
    }
}