#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
int arr[N];
int idx;
int sum[N];
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    if(sum[n] != 0){
        cout << "YES" << endl << 1 << endl << "1 " << n << endl;
    }
    else{
        idx = -1;
        for(int i = 1 ; i < n ; ++i){
            if(sum[i] != 0 && sum[n] - sum[i] != 0){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            cout << "YES" << endl << 2 << endl << "1 " << idx << endl << idx + 1 << " " << n << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}