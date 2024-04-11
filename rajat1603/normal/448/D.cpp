#include "bits/stdc++.h"
using namespace std;
long long n , m , k , l , r , mid;
int main(){
    cin >> n >> m >> k;
    l = 1;
    r = n * m;
    while(l < r){
        mid = l + r >> 1;
        long long cnt = 0;
        for(int i = 1 ; i <= n ; ++i){
            cnt += min(m , (mid) / i);
        }
        if(cnt >= k){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
}