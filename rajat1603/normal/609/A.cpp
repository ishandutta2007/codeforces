#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
int arr[N];
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    sort(arr + 1 , arr + 1 + n);
    reverse(arr + 1 , arr + 1 + n);
    arr[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        arr[i] += arr[i - 1];
        if(arr[i] >= m){
            cout << i << "\n";
            return 0;
        }
    }
}