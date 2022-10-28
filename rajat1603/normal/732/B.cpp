#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , k;
int arr[N];
int ans;
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 2 ; i <= n ; ++i){
        while(arr[i] + arr[i - 1] < k){
            ++arr[i];
            ++ans;
        }
    }
    cout << ans << endl;
    for(int i = 1 ; i <= n ; ++i){
        cout << arr[i] << " ";
    }
}