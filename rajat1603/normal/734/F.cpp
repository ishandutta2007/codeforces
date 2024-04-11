#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 31;
int n;
int a[N];
int b[N];
int c[N];
int d[N];
long long sumd;
long long suma;
int carry1[N];
int carry2[N];
void check(){
    for(int i = 0 ; i < LN ; ++i){
        int cnt = 0;
        for(int j = 1 ; j <= n ; ++j){
            cnt += ((a[j] >> i) & 1);
        }
        for(int j = 1 ; j <= n ; ++j){
            if(((a[j] >> i) & 1)){
                carry1[j] += cnt;
                carry2[j] += n;
            }
            else{
                carry2[j] += cnt;
            }
        }
        for(int j = 1 ; j <= n ; ++j){
            if(((b[j] >> i) & 1) != (carry1[j] & 1)){
                printf("-1\n");
                exit(0);
            }
            if(((c[j] >> i) & 1) != (carry2[j] & 1)){
                printf("-1\n");
                exit(0);
            }
            carry1[j] >>= 1;
            carry2[j] >>= 1;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(carry1[i] || carry2[i]){
            printf("-1\n");
            exit(0);
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , b + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , c + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        d[i] = b[i] + c[i];
    }
    suma = 0;
    sumd = 0;
    for(int i = 1 ; i <= n ; ++i){
        sumd += d[i];
    }
    suma = sumd / (2 * n);
    for(int i = 1 ; i <= n ; ++i){
        a[i] = (d[i] - suma) / n;
    }
    check();
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , a[i] , " \n"[i == n]);
    }
}