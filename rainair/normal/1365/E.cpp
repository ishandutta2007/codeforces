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

const int MAXN = 500+5;
LL a[MAXN];

int main(){
    int n;scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    LL ans = 0;
    FOR(i,1,n){
        FOR(j,i,n){
            FOR(k,j,n){
                ans = std::max(ans,a[i]|a[j]|a[k]);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}