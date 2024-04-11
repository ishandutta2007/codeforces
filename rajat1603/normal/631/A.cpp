#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
int a[N];
int b[N];
int ans = 0;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        cin >> b[i];
    }
    for(int l = 1 ; l <= n ; ++l){
        int x1 = 0;
        int x2 = 0;
        for(int r = l ; r <= n ; ++r){
            x1 |= a[r];
            x2 |= b[r];
            ans = max(ans , x1 + x2);
        }
    }
    cout << ans;
}