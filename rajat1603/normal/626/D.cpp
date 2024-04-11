#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int MAX = 5e3 + 3;
int n;
int arr[N];
long long num1;
long long num2;
int cnt[MAX];
long long suf[MAX];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            ++cnt[arr[j] - arr[i]];
        }
    }
    for(int i = MAX - 2 ; i >= 0 ; --i){
        suf[i] = suf[i + 1] + cnt[i];
    }
    num2 = n * (n - 1) / 2;
    num2 *= num2 * num2;
    for(int i = 1 ; i < MAX ; ++i){
        for(int j = 1 ; j < MAX ; ++j){
            long long num = cnt[i];
            num *= cnt[j];
            if(i + j + 1 < MAX){
                num *= suf[i + j + 1];
            }
            else{
                num = 0;
            }
            num1 += num;
        }
    }
    printf("%.9lf\n" , 1.0 * num1 / num2);
}