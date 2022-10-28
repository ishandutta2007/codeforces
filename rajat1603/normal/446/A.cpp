#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int l[N];
int r[N];
int n;
int ans = 1;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        l[i] = (arr[i] > arr[i - 1]) ? l[i - 1] + 1 : 1;
    }
    for(int i = n ; i >= 1 ; --i){
        r[i] = (arr[i] < arr[i + 1]) ? r[i + 1] + 1 : 1;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i - 1] < arr[i + 1] - 1){
            ans = max(ans , l[i - 1] + r[i + 1] + 1);
        }
        else{
            ans = max(ans , max(l[i - 1] + 1 , r[i + 1] + 1));
        }
    }
    printf("%d\n" , ans);
}