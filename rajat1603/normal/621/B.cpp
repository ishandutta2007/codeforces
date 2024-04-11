#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int offset = 5000;
int n;
int x[N];
int y[N];
int mark1[N];
int mark2[N];
long long ans = 0;
int main(){
    memset(mark1 , 0 , sizeof(mark1));
    memset(mark2 , 0 , sizeof(mark2));
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , x + i , y + i);
        ans += mark1[x[i] + y[i]];
        ans += mark2[x[i] - y[i] + offset];
        ++mark1[x[i] + y[i]];
        ++mark2[x[i] - y[i] + offset];
    }
    cout << ans;
}