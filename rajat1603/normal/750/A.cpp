#include "bits/stdc++.h"
using namespace std;
int n;
int k;
int main(){
    cin >> n >> k;
    k = 240 - k;
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(5 * i * (i + 1) / 2 <= k){
            ans = i;
        }
    }
    cout << ans << endl;
}