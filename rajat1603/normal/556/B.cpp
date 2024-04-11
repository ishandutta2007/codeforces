#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 10;
int n;
int arr[N];
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i];
    }
    for(int I = 1 ; I <= n ; ++I){
        bool b = 0;
        for(int i = 0 ; i < n ; ++i){
            b |= arr[i] != i;
        }
        if(b){
            for(int i = 0 ; i < n ; ++i){
                if(i & 1){
                    arr[i] = (arr[i] - 1 + n) % n;
                }
                else{
                    arr[i] = (arr[i] + 1) % n;
                }
            }
        }
        else{
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}