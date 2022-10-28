#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , d;
long long cur = 0;
long long ans = 0;
pair < int , int > arr[N];
int l = 1 , r = 2;
int main(){
    cin >> n >> d;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1 , arr + 1 + n);
    cur = arr[1].second;
    ans = cur;
    while(r <= n){
        while(r <= n && arr[r].first - arr[l].first < d){
            cur += arr[r].second;
            ++r;
        }
        ans = max(ans , cur);
        cur -= arr[l].second;
        ++l;
    }
    cout << ans;
}