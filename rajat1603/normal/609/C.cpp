#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int sum = 0;
int flr;
int extra;
int ans = 0;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        sum += arr[i];
    }
    flr = sum / n;
    extra = sum % n;
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] >= flr + 1){
            ans += arr[i] - flr;
            if(extra){
                --extra;
                --ans;
            }
        }
    }
    printf("%d\n" , ans);
}