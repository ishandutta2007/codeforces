#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int mn = 999;
int a , p;
int n;
int ans = 0;
int main(){
    scanf("%d" , &n);
    while(n--){
        scanf("%d %d" , &a , &p);
        mn = min(mn , p);
        ans += mn * a;
    }
    printf("%d\n" , ans);
}