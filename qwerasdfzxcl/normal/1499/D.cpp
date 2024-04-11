#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int c[20001000];

void solve(){
    int cc, d, x;
    scanf("%d %d %d", &cc, &d, &x);
    ll ans=0;
    for (int i=1;i*i<=x;i++){
        if (x%i) continue;
        int tmp = x/i;
        if ((tmp+d)%cc==0){
            int k=(tmp+d)/cc;
            ans += (1<<c[k]);
        }
        if (tmp==i) continue;
        tmp=i;
        if ((tmp+d)%cc==0){
            int k=(tmp+d)/cc;
            ans += (1<<c[k]);
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    c[1]=0;
    for (ll i=2;i<20001000;i++){
        if (c[i]) continue;
        c[i]=1;
        for (ll j=2;i*j<20001000;j++){
            c[i*j]++;
        }
    }
    while(t--){
        solve();
    }
    return 0;
}