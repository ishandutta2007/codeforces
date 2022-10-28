#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
pair < int , int > arr[N];
int ans = 0;
int cur = INT_MAX;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
    }
    sort(arr + 1 , arr + 1 + n);
    for(int i = n ; i >= 1 ; --i){
        if(arr[i].second < cur){
            cur = arr[i].first;
            ++ans;
        }
    }
    printf("%d\n" , ans);
}