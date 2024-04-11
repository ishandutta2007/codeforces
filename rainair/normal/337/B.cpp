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
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

inline LL gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
    int p = std::min(a*d,c*b),q = std::max(a*d,c*b);
    int k = gcd(p,q);
    p /= k;q /= k;
    printf("%d/%d\n",q-p,q);
    return 0;
}