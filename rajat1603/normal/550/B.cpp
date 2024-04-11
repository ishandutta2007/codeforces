#include "bits/stdc++.h"
using namespace std;
const int N = 16;
int n , l , r , x;
int arr[N];
int ans = 0;
int main(){
    cin >> n >> l >> r >> x;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    int p = 1 << n;
    for(int i = 3 ; i < p ; ++i){
        int sum = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int j = 0 ; j < n ; ++j){
            if(i & (1 << j)){
                sum += arr[j + 1];
                mn = min(mn , arr[j + 1]);
                mx = max(mx , arr[j + 1]);
            }
        }
        ans += (sum >= l && sum <= r && mx - mn >= x);
    }
    cout << ans;
}