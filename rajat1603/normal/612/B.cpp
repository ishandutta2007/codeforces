#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int inp;
int pos[N];
long long ans = 0;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp);
        pos[inp] = i;
    }
    for(int i = 2 ; i <= n ; ++i){
        ans += abs(pos[i] - pos[i - 1]);
    }
    cout << ans;
}