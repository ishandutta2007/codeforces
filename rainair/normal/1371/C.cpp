#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
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
#define int LL
signed main(){
    int T;scanf("%lld",&T);
    while(T--){
        LL a,b,n,m;scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
        LL t = std::min(n,std::llabs(a-b));
        n -= t;
        if(a > b) a -= t;
        else b -= t;
        puts(std::min(a,b) >= m&&a+b-m>=n ? "Yes":"No");
    }
    return 0;
}