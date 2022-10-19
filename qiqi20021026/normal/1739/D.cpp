#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,fa[N],mx[N];

int chk(int h){
    int ret=0;
    for (int i=1;i<=n;++i) mx[i]=0;
    for (int i=n;i>=2;--i){
        ++mx[i];
        if (mx[i]==h-1&&fa[i]!=1){
            mx[i]=0;
            ++ret;
        }
        mx[fa[i]]=max(mx[fa[i]],mx[i]);
    }
    return ret;
}
void solve(){
    cin>>n>>m;
    for (int i=2;i<=n;++i) cin>>fa[i];
    int l=2,r=n,ans=n;;
    while (l<=r){
        int mid=(l+r)>>1;
        if (chk(mid)<=m){ans=mid; r=mid-1;}
        else l=mid+1;
    }
    cout<<ans-1<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}