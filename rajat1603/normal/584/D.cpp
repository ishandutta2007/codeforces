#include "bits/stdc++.h"
using namespace std;
int n;
const int N = 1e4 + 4;
bool isprime(int n){
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin >> n;
    if(isprime(n)){
        cout << "1\n" << n;
        return 0;
    }
    vector < int > ans;
    for(int i = n - 2 ; i >= 2 ; --i){
        if(isprime(i)){
            ans.emplace_back(i);
            n -= i;
            break;
        }
    }
    if(isprime(n)){
        cout << 2 << endl;
        cout << ans[0] << " " << n;
        return 0;
    }
    for(int i = 2 ; i < n - 1 ; ++i){
        if(isprime(i) && isprime(n - i)){
            cout << 3 << endl;
            cout << ans[0] << " " << i << " " << n - i;
            return 0;
        }
    }
}