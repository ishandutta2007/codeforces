#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod=998244353;

int main(){
    LL n,m; cin>>n>>m;
    vector<int> pr,vis(n+1);
    for (int i=2;i<=n;++i){
        if (!vis[i]){
            pr.push_back(i);
        }
        for (int j:pr){
            if (i*j>n) break;
            vis[i*j]=1;
            if (i%j==0) break;
        }
    }
    LL ans=0,now=1,tmp=1,mm=m;
    for (int i=1;i<=n;++i){
        tmp=tmp*(mm%mod)%mod;
        ans=(ans+tmp)%mod;
        if (!vis[i]) m/=i;
        now=now*(m%mod)%mod;
        ans=(ans-now+mod)%mod;
    }
    cout<<ans<<'\n';
}