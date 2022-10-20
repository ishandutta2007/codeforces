#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int cur = 0, i = 1;
    for (;cur<n;i+=2) cur += i;
    printf("%d\n", i/2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}