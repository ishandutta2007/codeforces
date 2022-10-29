// #include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
// head

const int mod=1e9+7;
const int N=2e6+5;
int T,n;

ll powmod(ll x,ll k) {
    ll res=1;
    for (;k;k>>=1,x=x*x%mod) if (k&1) res=res*x%mod;
    return res;
}
ll fac[N],inv[N];
void pre() {
    fac[0]=inv[0]=1;
    rep(i,1,N) fac[i]=fac[i-1]*i%mod;
    rep(i,1,N) inv[i]=powmod(fac[i],mod-2);
}
ll comb(ll n,ll m) {
    if (n<m) return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main() {
    pre();
    cin>>T;
    while (T--) {
        scanf("%d",&n);
        printf("%lld\n",fac[2*n]*inv[2]%mod);
    }
    
    return 0;   
}