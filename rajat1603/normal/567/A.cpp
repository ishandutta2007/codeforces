#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
long long arr[N];
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    arr[0] = -1LL << 40;
    arr[n + 1] = 1LL << 40;
    for(int i = 1 ; i <= n ; ++i){
        cout << min(arr[i] - arr[i - 1] , arr[i + 1] - arr[i]) << " " << max(arr[n] - arr[i] , arr[i] - arr[1]) << endl;
    }
}