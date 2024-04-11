#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int mn = 1;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 2 ; i <= n ; ++i){
        if(arr[i] < arr[i - 1]){
            for(int j = i + 1; j <= n ; ++j){
                if(arr[j] < arr[j - 1]){
                    cout << "-1";
                    return 0;
                }
            }
            for(int j = 1 ; j < i ; ++ j){
                if(arr[j] < arr[(j == 1) ? n : j - 1]){
                    cout << "-1";
                    return 0;
                }
            }
            cout << (n - i + 1) % n;
            return 0;
        }
    }
    cout << "0";
}