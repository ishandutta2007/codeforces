#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int m;
int l , r;
int mx;
int main(){
    scanf("%d %d" , &n , &m);
    mx = 1e9;
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &l , &r);
        mx = min(mx , r - l + 1);
    }
    printf("%d\n" , mx);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , i % mx , " \n"[i == n]);
    }
}