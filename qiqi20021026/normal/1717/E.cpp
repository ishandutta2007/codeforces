#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 120000

const LL mod=1000000007;
LL n,vis[N],mu[N],s1[N],s2[N];
vector<LL> pr;

void upd(LL &x,LL y){x=(x+y)%mod;}

void init(LL n){
    for (LL i=1;i<=n;++i){
        s1[i]=i/gcd(n,i);
        s2[i]=i/gcd(n,i)*i%mod;
        upd(s1[i],s1[i-1]);
        upd(s2[i],s2[i-1]);
    }
    mu[1]=1;
    for (LL i=2;i<=n;++i){
        if (!vis[i]){
            pr.push_back(i);
            mu[i]=-1;
        }
        for (LL j:pr){
            if (i*j>n) break;
            vis[i*j]=1;
            if (i%j==0){
                mu[i*j]=0;
                break;
            }
            else{
                mu[i*j]=-mu[i];
            }
        }
    }
}

int main(){
    cin>>n;
    init(n);
    LL ans=0;
    for (LL k=1;k<=n;++k){
        if (!mu[k]) continue;
        for (LL s=2;s*k<=n;++s){
            LL tmp=(n*s1[n/s/k]-s*k*s2[n/s/k])%mod;
            upd(ans,mu[k]*(s-1)*tmp);
        }
    }
    cout<<(ans+mod)%mod<<'\n';

    return 0;
}