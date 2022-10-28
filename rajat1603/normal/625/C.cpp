#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n , k;
int arr[N][N];
int sum;
int cur = 0;
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j < k ; ++j){
            arr[i][j] = ++cur;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = k ; j <= n ; ++j){
            arr[i][j] = ++cur;
            if(j == k){
                sum += cur;
            }
        }
    }
    cout << sum << endl;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}