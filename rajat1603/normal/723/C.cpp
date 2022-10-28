#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
int n , m;
int arr[N];
int freq[N];
int ans1;
int ans2;
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        if(arr[i] <= m){
            ++freq[arr[i]];
        }
    }
    ans1 = n / m;
    ans2 = 0;
    for(int i = 1 ; i <= m ; ++i){
        while(freq[i] < ans1){
            for(int j = 1 ; j <= n ; ++j){
                if(arr[j] > m || freq[arr[j]] > ans1){
                    if(arr[j] <= m)
                        --freq[arr[j]];
                    arr[j] = i;
                    ++freq[i];
                    ++ans2;
                    break;
                }
            }
        }
    }
    printf("%d %d\n" , ans1 , ans2);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , arr[i] , " \n"[i == n]);
    }
}