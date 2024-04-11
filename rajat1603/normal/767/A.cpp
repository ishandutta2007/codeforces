#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int all[N];
int cur;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        all[i] = 0;
    }
    cur = n;
    for(int i = 1 ; i <= n ; ++i){
        all[arr[i]] = 1;
        while(all[cur]){
            printf("%d " , cur);
            --cur;
        }
        printf("\n");
    }
}