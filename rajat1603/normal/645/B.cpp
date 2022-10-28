#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int l , r;
long long ans = 0;
int main(){
    cin >> n >> k;
    l = 1;
    r = n;
    while(l < r && k){
        --k;
        ans += (r - l - 1) * 2 + 1;
        ++l;
        --r;
    }
    cout << ans;
}