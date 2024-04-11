#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , k;
int inp;
int ans = 0;
int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> inp;
        for(int j = 0 ; j < 3 && inp >= k ; ++j){
            inp -= k;
        }
        ans += inp;
    }
    cout << ans;
}