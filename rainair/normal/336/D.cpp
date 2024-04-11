#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
#define SFOR(i,a,b,x) for(R int i = a;i <= b;i += x)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;

const int ha = 1e9+7;
int N,M,G;
const int MAXN = 200000 + 5;
LL mul[MAXN],inv[MAXN];

inline void init(){
    mul[0] = mul[1] = 1;
    FOR(i,2,N+M){
        mul[i] = (mul[i-1]*i)%ha;
    }
    inv[1] = 1;
    FOR(i,2,N+M){
        inv[i]= ha - (LL)(ha/i)*inv[ha%i]%ha;
    }
    inv[0] = 1;
    FOR(i,1,N+M) inv[i] = (inv[i-1]*inv[i])%ha;
}

inline LL C(int u,int d){
    return ((mul[u]*inv[d])%ha*inv[u-d])%ha;
}

int main(){
    read(N);read(M);read(G);
    init();
    if(!N){
        if((M == 1 && G) || (M > 1 && !G)) puts("1");
        else puts("0");
        return 0;
    }
    if(!M){
        if((N&1 && !G) || (!(N&1) && G)) puts("1");
        else puts("0");
        return 0;
    }
    LL ans = 0;
    SFOR(i,1,N,2){
        if(N-i+M-1) ans = (ans + C(N+M-i-1,M-1)%ha)%ha;
    }
    if(!(N%2) && M == 1) ans++;
    if(!G) ans = (C(N+M,M)-ans+ha)%ha;
    printf("%lld\n",ans%ha);
    return 0;
}