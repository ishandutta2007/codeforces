#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
int arr[N];
int ans = 0;
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            cin >> arr[j];
        }
        ans = max(ans , *min_element(arr + 1 , arr + 1 + m));
    }
    cout << ans;
}