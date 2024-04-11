#include "bits/stdc++.h"
using namespace std;
const int N = 400;
int n;
int a[N];
int b[N];
int c[N];
int main(){
    cin >> n;
    a[0] = 0;
    for(int i = 1 ; i < n ; ++i){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    b[0] = 0;
    for(int i = 1 ; i < n ; ++i){
        cin >> b[i];
        b[i] += b[i - 1];
    }
    for(int i = 1 ; i <= n ; ++i){
        cin >> c[i];
    }
    int ans = 9999999;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            ans = min(ans , a[i - 1] + c[i] + b[n - 1] - b[i - 1] + b[n - 1] - b[j - 1] + c[j] + a[j - 1]);
        }
    }
    cout << ans;
}