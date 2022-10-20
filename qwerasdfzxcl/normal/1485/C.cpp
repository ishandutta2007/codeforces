#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void solve(){
    int x, y;
    scanf("%d %d", &x, &y);
    int sqx=sqrt(x);
    ll ans=0;
    for (int i=1;i<=sqx;i++){
        ll tmp=(ll)i*i+2*i;
        ll tmp2=min((ll)x, (ll)i*(y+1));
        if (tmp2>=tmp)ans += (tmp2-tmp)/i+1;
    }
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