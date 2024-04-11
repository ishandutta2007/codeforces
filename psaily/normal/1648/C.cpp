#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define SZ(x) ((int)x.size())
#define mp make_pair
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long double db;
typedef unsigned long long ull;
// head

const int mod=998244353;
const int N=2e5+5;
int n,m;
int a[N],b[N],cnt[N];

ll fac[N],inv[N];
ll powmod(ll x,ll k) {
    ll res=1;
    for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
    return res;
}
void prep() {
    fac[0]=inv[0]=1;
    rep(i,1,N) fac[i]=fac[i-1]*i%mod;
    rep(i,1,N) inv[i]=powmod(fac[i],mod-2);
}

struct bit {
    int sum[N];
    int lowbit(int x) {return x&(-x);}
    void modify(int x,int a) {
        for (;x<N;x+=lowbit(x)) sum[x]+=a;
    }
    int query(int x) {
        int res=0;
        for (;x;x-=lowbit(x)) res+=sum[x];
        return res;   
    }
}bit;

int main() {
    prep();
    
    scanf("%d%d",&n,&m);
    rep(i,1,n+1) scanf("%d",&a[i]),cnt[a[i]]++;
    rep(i,1,m+1) scanf("%d",&b[i]);
    ll bas=1;
    rep(i,1,N) if (cnt[i]) {
        bas=bas*inv[cnt[i]]%mod;
        bit.modify(i,cnt[i]);
    }
    ll ans=0;
    rep(i,1,min(n,m)+1) {
        // arrange b
        (ans+=bas*fac[n-i]%mod*bit.query(b[i]-1)%mod)%=mod;
        // bug(ans),debug(bas);
        if (!cnt[b[i]]) break;
        bas=bas*cnt[b[i]]%mod;
        cnt[b[i]]--,bit.modify(b[i],-1);
        if (i==n&&m>n) ans++;
    }
    printf("%lld\n",ans%mod);
    // debug(499122177*2%mod);
    
    
    return 0;
}