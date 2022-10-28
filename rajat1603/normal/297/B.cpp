#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m , k;
int arr1[N];
int arr2[N];
int main(){
    cin >> n >> m >> k;
    if(n > m){
        cout << "YES";
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr1[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        cin >> arr2[i];
    }
    sort(arr1 + 1 , arr1 + n + 1);
    sort(arr2 + 1 , arr2 + m + 1);
    for(int i = n ; i >= 1 ; --i){
        if(arr1[i] > arr2[i + m - n]){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}