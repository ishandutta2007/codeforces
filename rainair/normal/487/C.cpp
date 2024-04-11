#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
int n;

inline int qpow(int a,int n=::n-2){
    int res = 1;
    while(n){
        if(n & 1) res = res*a % (::n);
        a = a*a%(::n);
        n >>= 1;
    }
    return res;
}

inline bool pd(int x){
    int q = std::sqrt(1.0*x);
    if(x == 1) return false;
    FOR(i,2,q) if(!(x%i)) return false;
    return true;
}

signed main(){
    scanf("%I64d",&n);
    if(n == 1){
        puts("YES\n1");
        return 0;
    }
    if(n == 4){
        puts("YES\n1\n3\n2\n4");
        return 0;
    }
    if(!pd(n)){
        puts("NO");
        return 0;
    }
    puts("YES\n1");
    FOR(i,2,n-1){
        printf("%I64d\n",i*qpow(i-1)%n);
    }
    printf("%I64d\n",n);
    return 0;
}