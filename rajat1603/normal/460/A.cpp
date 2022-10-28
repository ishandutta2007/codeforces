#include "bits/stdc++.h"
using namespace std;
int n , m;
int cur = 1;
int ans = 0;
int main(){
    cin >> n >> m;
    while(n){
        --n;
        if(cur == m){
            cur = 0;
            ++n;
        }
        ++ans;
        ++cur;
    }
    cout << ans;
}