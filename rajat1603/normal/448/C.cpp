#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 5;
int arr[N];
int n;
int solve(int l , int r , int height){
    if(r < l){
        return 0;
    }
    int mn = INT_MAX;
    for(int i = l ; i <= r ; ++i){
        mn = min(mn , arr[i]);
    }
    int last = l;
    int res = 0;
    for(int i = l ; i <= r ; ++i){
        if(arr[i] == mn){
            res += solve(last , i - 1 , mn);
            last = i + 1;
        }
    }
    res += solve(last , r , mn);
    res += mn - height;
    return min(res , r - l + 1);
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    cout << solve(1 , n , 0);
}