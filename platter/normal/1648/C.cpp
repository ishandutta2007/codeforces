#include <bits/stdc++.h>
using namespace std;

long long fac[200001];
int tree[200001];

int sum(int i) {
    int ret=0;
    while (i>0) {
        ret+=tree[i];
        i-=(i&-i);
    }
    return ret;
}

void update(int i,int val) {
    while (i<=200000) {
        tree[i]+=val;
        i+=(i&-i);
    }
}

int n,m;
int s[200000];
int t[200000];
const int mod=998244353;

long long fastpow(long long a,long long b) {
    if (b==0) {
        return 1;
    }
    if (b%2==1) {
        return (fastpow(a,b-1)*a)%mod;
    }
    long long half=fastpow(a,b/2);
    return (half*half)%mod;
}

int main(void) {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&s[i]);
        update(s[i],1);
    }
    for(int i=0;i<m;i++) {
        scanf("%d",&t[i]);
    }
    fac[0]=1;
    for(int i=1;i<=200000;i++) {
        fac[i]=(fac[i-1]*i)%mod;
    }
    long long val=fac[n];
    for(int i=1;i<=200000;i++) {
        val*=fastpow(fac[sum(i)-sum(i-1)],mod-2);
        val%=mod;
    }
    long long ret=0;
    bool flag=true;
    for(int i=0;i<n;i++) {
        if (i>=m) {
            break;
        }
        long long nval=val;
        nval*=fastpow(n-i,mod-2);
        nval%=mod;
        nval*=sum(t[i]-1);
        nval%=mod;
        ret+=nval;
        ret%=mod;
        if (sum(t[i])==sum(t[i]-1)) {
            flag=false;
            break;
        }
        val*=fastpow(n-i,mod-2);
        val%=mod;
        val*=sum(t[i])-sum(t[i]-1);
        val%=mod;
        update(t[i],-1);
    }
    if (flag&&m>n) {
        ret+=val;
        ret%=mod;
    }
    printf("%lld",ret);
}