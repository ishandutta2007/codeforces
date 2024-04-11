#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int x[1010], y[1010];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d %d", x+i, y+i);
    }
    if (n%2==1){
        printf("1\n");
        return;
    }
    sort(x, x+n);
    sort(y, y+n);
    ll ans=x[n/2]-x[n/2-1]+1;
    ans *= (y[n/2]-y[n/2-1]+1);
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}