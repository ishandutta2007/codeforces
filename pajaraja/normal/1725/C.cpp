#include<bits/stdc++.h>
#define maxn 400000
#define mod 998244353
using namespace std;
inline long long step(long long a,long long b) {
    long long ret=1;
    while(b>0) {
        if(b%2==1) ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}
inline long long inverse(long long a) {
    return step(a,mod-2);
}
int n,m;
int d[maxn];
long long pref[maxn];
long long fact[maxn];
long long invfact[maxn];
map<long long,int> cnt;
long long s;
long long binom(long long n,long long k) {
    if(k<0 || k>n) return 0;
    return (fact[n]*((invfact[k]*invfact[n-k])%mod))%mod;
}
int main() {
    fact[0]=invfact[0]=1;
    for(int i=1;i<maxn;i++) {
        fact[i]=(fact[i-1]*i)%mod;
        invfact[i]=inverse(fact[i]);
    }
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&d[i]);
        s+=d[i];
    }
    for(int i=1;i<n;i++) {
        pref[i]=pref[i-1]+d[i-1];
    }
    if(s%2!=0) {
        printf("%lld",step(m,n));
        return 0;
    }
    s/=2;
    for(int i=0;i<n;i++) cnt[pref[i]%s]++;
    long long ret=0;
    long long o=0;
    long long p=0;
    for(auto val:cnt) {
        int c=val.second;
        if(c==1) o++;
        else p++;
    }
    for(int i=0;i<=p;i++) {
        long long b1=binom(p,i);
        long long b2=binom(m,i);
        long long f=fact[i];
        long long s1=step(m-i,o);
        long long s2=step((1ll*(m-i)*(m-i-1))%mod,p-i);
        long long ad=((((((((b1*b2)%mod)*f)%mod)*s1)%mod)*s2)%mod);
        ret=(ret+ad)%mod;
    }
    printf("%lld",ret);
    return 0;
}