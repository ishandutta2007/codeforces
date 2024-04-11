#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int mod=998244353;
#define N 120'000

int n,m;
LL a[N],s[N];

void solve(){
    cin>>n>>m;
    for (int i=1;i<=m;++i) cin>>s[i];
    for (int i=2;i<=m;++i) a[i]=s[i]-s[i-1];
    if (m==1){
        cout<<"YES\n"; return;
    }
    for (int i=2;i<m;++i) if (a[i]>a[i+1]){
        cout<<"NO\n"; return;
    }
    int t=n-m+1;
    int x=s[1]>=0?(s[1]+t-1)/t:s[1]/t;
    cout<<(x<=a[2]?"YES\n":"NO\n");
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}