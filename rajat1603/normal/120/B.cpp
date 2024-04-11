#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 10;
int n , k;
bool arr[N];
int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i  = k ; i <= n ; ++i){
        if(arr[i]){
            cout << i;
            return 0;
        }
    }
    for(int i = 1 ; i < k ; ++i){
        if(arr[i]){
            cout << i;
            return 0;
        }
    }
}