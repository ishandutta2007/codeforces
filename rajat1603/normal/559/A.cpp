#include "bits/stdc++.h"
using namespace std;
long long arr[6];
int main(){
    for(int i = 0 ; i < 6 ; ++i){
        cin >> arr[i];
    }
    long long res = 0;
    for(int i = 0 ; i < 3 ; ++i){
        res += arr[i];
    }
    res *= res;
    for(int i = 0 ; i < 6 ; i += 2){
        res -= arr[i] * arr[i];
    }
    cout << res;
}