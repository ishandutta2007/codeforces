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

const int MAXN = 2e5 + 5;
const int ha = 998244353;
int n,k;
int a[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    LL sm = 0;ROF(i,n,n-k+1) sm += i;
    printf("%lld ",sm);
    int gx = 0;
    bool fg = 0;
    int ans = 1;
    FOR(i,1,n){
        if(a[i] < n-k+1) gx++;
        else{
            if(!fg){
                fg = 1;gx = 1;continue;
            }
            else{
                ans = 1ll*ans*gx%ha;
                gx = 1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}