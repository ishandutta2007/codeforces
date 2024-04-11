#include "bits/stdc++.h"
using namespace std;
int n;
int x;
int arr[3];
int main(){
    cin >> n >> x;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    n %= 6;
    for(int i = 1 ; i <= n ; ++i){
        if(i & 1){
            swap(arr[0] , arr[1]);
        }
        else{
            swap(arr[1] , arr[2]);
        }
    }
    cout << arr[x] << endl;
}