#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
int mx;
int main(){
    cin >> n;
    mx = 0;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        mx = max(mx , arr[i]);
    }   
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        ans += mx - arr[i];
    }
    cout << ans << endl;
}