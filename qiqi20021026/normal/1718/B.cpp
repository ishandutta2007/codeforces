#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f[105],a[105];

void solve(){
    LL n; cin>>n;
    LL sum=0;
    for (LL i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    f[0]=0; f[1]=1;
    LL m=1;
    while (f[m]<sum){
        sum-=f[m];
        ++m;
        f[m]=f[m-1]+f[m-2];
    }
    if (f[m]>sum){
        puts("NO");
        return;
    }
    LL lst=0;
    for (LL i=m;i;--i){
        LL k=0;
        for (LL j=1;j<=n;++j){
            if (a[j]>a[k]&&j!=lst) k=j;
        }
        if (a[k]<f[i]){
            puts("NO");
            return;
        }
        a[k]-=f[i];
        lst=k;
    }
    puts("YES");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--) solve();
}