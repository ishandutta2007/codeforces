#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll p[110], s[110];

void solve(){
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    for (int i=0;i<n;i++) scanf("%lld", p+i);
    s[0]=p[0];
    for (int i=1;i<n;i++) s[i]=s[i-1]+p[i];
    ll ans=0;
    for (int i=1;i<n;i++){
        ll tmp=p[i]*100/k-s[i-1];
        if (p[i]*100%k!=0) tmp++;
        if (tmp<0) tmp=0;
        ans=max(ans, tmp);
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