#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n , k , arr[N];
int ans = 0;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    while(1){
        sort(arr + 1 , arr + 1 + n , [](int a , int b){
            return (a % 10) > (b % 10);
        });
        bool x = 1;
        bool y = 1;
        for(int i = 1 ; i <= n ; ++i){
            int temp = 10 - (arr[i] % 10);
            if(arr[i] != 100){
                x = 0;
            }
            if(arr[i] == 100 || (k < temp)){
                continue;
            }
            y = 0;
            k -= temp;
            arr[i] += temp;
        }
        if(x || y){
            break;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        ans += arr[i] / 10;
    } 
    printf("%d\n" , ans);
}