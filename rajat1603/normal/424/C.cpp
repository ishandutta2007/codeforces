#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int prefix[N];
int n;
int ans = 0;
int main(){
    scanf("%d" , &n);
    prefix[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        prefix[i] = prefix[i - 1] ^ i;
    }
    int temp;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &temp);
        if((n / i) & 1){
            ans ^= prefix[i - 1];
        }
        ans ^= prefix[n % i];
        ans ^= temp;
    }
    printf("%d\n" , ans);
}