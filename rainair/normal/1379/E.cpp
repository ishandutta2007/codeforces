#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int f[MAXN],tot;

inline bool pd(int n,int k){
    if(n == 1) return k == 0;
    if(!(n&1) || k > (n-3)/2) return 0;
    if(n == 9) return k != 2 && k != 0;
    if(__builtin_popcount(n+1) == 1) return k != 1;
    return k != 0;
}

inline bool get(int x,int y){
    if(x < y) std::swap(x,y);
    return x >= 2*y;
}

inline int work(int n,int k){// construct (n,k)
    assert(pd(n,k));
    int v = ++tot;
    if(n == 1) return v;
    if(k == 0){
        f[work(n>>1,k)] = f[work(n>>1,k)] = v;
        return v;
    }
    if(k == 1){
        // (2^x-1,0),(n-2^x,1)
        int b = 2;
        while(n-b >= 0 && !pd(n-b,!get(b-1,n-b))) b <<= 1;
        f[work(b-1,0)] = f[work(n-b,!get(b-1,n-b))] = v;
        return v;
    }
    FOR(n1,1,std::min(10,n-2)){
        int c = get(n1,n-n1-1);
        FOR(k1,0,std::min(10,k-c)){
            if(pd(n1,k1) && pd(n-n1-1,k-k1-c)){
                f[work(n1,k1)] = f[work(n-n1-1,k-k1-c)] = v;
                return v;
            }
        }
    }
    assert(0);
}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    if(!pd(n,k)){
        puts("NO");
        return 0;
    }
    work(n,k);
    puts("YES");
    FOR(i,1,n) printf("%d%c",f[i]," \n"[i==n]);
    return 0;
}
/*
n 
k <= (n-3)/2
n=1,k=0
n=2^k-1,k != 1
n!=2^k-1,k != 0
n=9,k!=2
*/