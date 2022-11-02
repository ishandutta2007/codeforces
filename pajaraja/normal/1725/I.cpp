#include<bits/stdc++.h>
#define maxn 200005
#define mod 998244353
using namespace std;
inline long long step(long long a,long long b) {
    long long ret=1;
    while(b>0) {
        if(b%2==1) ret=(ret*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ret;
}
inline long long inverse(long long a) {
    return step(a,mod-2);
}
int n;
vector<int> comp[maxn];
int cc[maxn];
long long numw[maxn];
long long fact[maxn];
long long invfact[maxn];
inline long long binom(long long n,long long k) {
    if(k<0 || k>n) return 0;
    return (((fact[n]*invfact[k])%mod)*invfact[n-k])%mod;
}
void mrg(int u,int v) {
    u=cc[u];
    v=cc[v];
    if(comp[v].size()>comp[u].size()) swap(u,v);

    long long lsz = comp[u].size();
    long long rsz = comp[v].size();

    long long mult = (lsz * rsz) %mod;

    long long lcnt = numw[u];
    long long rcnt = numw[v];

    long long cnt = (lcnt * rcnt)%mod;

    cnt = (((cnt * mult)%mod)*mult)%mod;

    numw[u] = cnt;

    for(auto w:comp[v]) {
        comp[u].push_back(w);
        cc[w]=u;
    }
    comp[v].clear();
}
int main() {
    fact[0]=invfact[0]=1;
    for(int i=1;i<maxn;i++) {
        fact[i]=(i*fact[i-1])%mod;
        invfact[i]=inverse(fact[i]);
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        cc[i]=i;
        comp[i].push_back(i);
        numw[i]=1;
    }
    for(int i=0;i<n-1;i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        mrg(u,v);
    }
    long long sol=numw[cc[1]];
    for(int i=2*n-3;i>=0;i-=2) sol=(sol*i)%mod;
    printf("%lld",sol);
    return 0;
}