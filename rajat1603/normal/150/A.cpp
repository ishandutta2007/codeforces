#include "bits/stdc++.h"
using namespace std;
long long n;
int main(){
    cin >> n;
    long long ans = -1;
    long long init = n;
    for(long long i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            if(ans > 0){
                cout << "1\n" << ans * i;
                return 0;
            }
            ans = i;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(ans == -1){
        cout << "1\n0";
    }
    else{
        if(ans * ans != init && ((init % (ans * ans)) == 0)){
            cout << "1\n" << ans * ans ;
        }
        else
            cout << 2 ;
    }
}