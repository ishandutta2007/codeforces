#include <cstdio>
#include <cstring>

int mod=1000000007;
int n,m;
long long lisdp[1055][15];
long long ldsdp[1055][15];

long long lisans(int val,int l) {
    if (lisdp[val][l]!=-1) {
        return lisdp[val][l];
    }
    if (l==1) {
        return 1;
    }
    long long ret=0;
    for(int i=val;i<=n;i++) {
        ret+=lisans(i,l-1);
        ret=ret%mod;
    }
    lisdp[val][l]=ret;
    return ret;
}

long long ldsans(int val,int l) {
    if (ldsdp[val][l]!=-1) {
        return ldsdp[val][l];
    }
    if (l==1) {
        return 1;
    }
    long long ret=0;
    for(int i=val;i>=1;i--) {
        ret+=ldsans(i,l-1);
        ret=ret%mod;
    }
    ldsdp[val][l]=ret;
    return ret;
}

int main(void) {
    scanf("%d %d",&n,&m);
    memset(lisdp,-1,sizeof(lisdp));
    memset(ldsdp,-1,sizeof(ldsdp));
    long long ret=0;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            ret+=lisans(j,m)*ldsans(i,m);
            ret=ret%mod;
        }
    }
    printf("%lld",ret);
    return 0;
}