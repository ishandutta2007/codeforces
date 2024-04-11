/*
 * Author: RainAir
 * Time: 2020-03-06 10:22:35
 */
#include<bits/stdc++.h>

#define fi first
#define se second
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000+5;
const int ha = 1e9 + 7;
int fac[MAXN],inv[MAXN];

inline int qpow(int a,int n=ha-2){
    int res=1;
    while(n){
        if(n&1)res=1ll*res*a%ha;
        a=1ll*a*a%ha;n>>=1;
    }
    return res;
}

int C(int n,int m){
    if(n < m) return 0;
    if(!m) return 1;
    return 1ll*fac[n]*inv[m]%ha*inv[n-m]%ha;
}

int n,m;

inline int D(int n,int m){ // n m  
    return C(n+m-1,m-1);
}

int main(){
    scanf("%d%d",&n,&m);
    fac[0] = 1;FOR(i,1,MAXN-1) fac[i]=1ll*fac[i-1]*i%ha;
    inv[MAXN-1]=qpow(fac[MAXN-1]);ROF(i,MAXN-2,0) inv[i]=1ll*inv[i+1]*(i+1)%ha;
    int ans = 0;
    FOR(a,1,n){
        FOR(b,a,n){ // b >= a
            int t = b-a;
            (ans += 1ll*D(t,2*m-1)) %= ha;
        }
    }
     printf("%d\n",ans);
    return 0;
}