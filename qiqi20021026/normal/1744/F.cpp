#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> pos(n);
    for (int i=0;i<n;++i){
        int x; cin>>x;
        pos[x]=i;
    }
    int l=n-1,r=0;
    long long ans=0;
    for (int i=0;i<n;++i){
        int j=i*2;
        if (j>n) break;
        l=min(l,pos[i]);
        r=max(r,pos[i]);
        int L=r-j,R=l+j;
        L=max(L,0); R=min(R,n-1);
        ans+=max(0,(R-L-j+1));
        j=i*2+1;
        if (j>n) break;
        L=r-j,R=l+j;
        L=max(L,0); R=min(R,n-1);
        ans+=max(0,(R-L-j+1));
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}