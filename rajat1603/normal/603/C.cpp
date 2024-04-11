#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
int res;
int solve(int val){
    if(val <= 3){
        return val & 1;
    }
    if(val & 1){
        return 0;
    }
    int v1 = solve(val - 1);
    int v2 = solve(val >> 1);
    if(0 == v1 || 0 == v2){
        if(1 == v1 || 1 == v2){
            return 2;
        }
        return 1;
    }
    return 0;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        res ^= (k & 1) ? solve(arr[i]) : ((arr[i] < 3) ? arr[i] : (1 - (arr[i] & 1)));
    }
    puts(res ? "Kevin" : "Nicky");
}