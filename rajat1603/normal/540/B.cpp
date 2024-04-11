#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 10;
int n , k , p , x , y;
int arr[N];
int sum = 0;
int main(){
    cin >> n >> k >> p >> x >> y;
    for(int i = 1 ; i <= k ; ++i){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum + n - k > x){
        cout << -1;
    }
    else{
        for(int i = k + 1 ; i <= n ; ++i){
            sum += y;
            arr[i] = y;
        }
        int idx = k + 1;
        while(sum > x){
            if(arr[idx] == 1){
                ++idx;
                continue;
            }
            arr[idx]--;
            sum--;
        }
        vector < int > print;
        for(int i = k + 1 ; i <= n ; ++i){
            print.emplace_back(arr[i]);
        }
        sort(arr + 1 , arr + 1 + n);
        if(arr[(n >> 1) + 1] < y){
            cout << -1;
        }
        else{
            for(int x : print){
                cout << x << " ";
            }
        }
    }
}