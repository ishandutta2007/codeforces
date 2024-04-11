#include "bits/stdc++.h"
using namespace std;
short n , x[2003] , y[2003];
int ans = 0;
int main(){
    scanf("%hd" , &n);
    for(int i = 1 ; i <= n ; ++i)
        scanf("%hd %hd" , x + i , y + i);
    for(int i = 1 ; i < n - 1 ; ++i)
        for(int j = i + 1 ; j < n ; ++j)
            for(int k = j + 1 ; k <= n ; ++k)
                ans += !!(x[i] * (  y[j] - y[k]) + x[j] * (y[k] - y[i]) + x[k] * (y[i] - y[j]));
    printf("%d\n" , ans);
}