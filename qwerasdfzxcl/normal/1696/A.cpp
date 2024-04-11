#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int n, z;
    scanf("%d %d", &n, &z);
    int ans = 0;
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d", &x);
        ans = max(ans, x | z);
    }
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