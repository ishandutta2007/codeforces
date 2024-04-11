#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 19;
int arr[N];
int n;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    int idx = (n >> 1) + 1;
    int ans = n;
    for(int i = 1 ; i <= (n >> 1) && idx <= n ;){
        while(idx <= n && i <= (n >> 1)){
            if(arr[idx] >= arr[i] + arr[i]){
                ++i;
                ++idx;
                --ans;
            }
            else{
                ++idx;
            }
        }
    }
    cout << ans;
}