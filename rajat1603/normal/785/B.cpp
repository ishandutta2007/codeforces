#include "bits/stdc++.h"
using namespace std;
int n;
int minr;
int maxl;
int l , r;
int main(){
    scanf("%d" , &n);
    minr = 1e9 + 7;
    maxl = 0;
    while(n--){
        scanf("%d %d" , &l , &r);
        minr = min(minr , r);
        maxl = max(maxl , l);
    }
    scanf("%d" , &n);
    int ans = 0;
    while(n--){
        scanf("%d %d" , &l , &r);
        ans = max(ans , l - minr);
        ans = max(ans , maxl - r);
    }
    printf("%d\n" , ans);
}