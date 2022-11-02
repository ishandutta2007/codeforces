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

#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL

int b,k;
int a[1000000];

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = (res*a);
        a = (a*a);
        n >>= 1;
    }
    return res;
}

signed main(){
    //freopen("11.in","r",stdin);
    scanf("%I64d%I64d",&b,&k);
    FOR(i,1,k) scanf("%I64d",a+i);
    int res = 0;
    FOR(i,1,k) res = (res + a[i]*qpow(b,k-i));
    puts(res&1 ? "odd" : "even");
    return 0;
}