#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    int ans = n/10;
    if (n%10==9) ans++;
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}