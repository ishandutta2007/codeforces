/*
 * Time: 2019-11-25 12:44:45
 */
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

const int MAXN = 1e3 + 5;
int a[MAXN];
P b[MAXN];
int ans[MAXN][MAXN];
int n;

int main(){
    scanf("%d",&n);
    FOR(i,0,n-1) scanf("%d",a+i),b[i] = MP(a[i],i);
    std::sort(b,b+n);std::reverse(b,b+n);
    int st = 0;
    FOR(i,0,n-1){
        int ps = b[i].se,x = b[i].fi;
        FOR(j,0,x-1){
            ans[(st+j)%(n+1)][ps] = 1;
        }
        st++;
    }
    printf("%d\n",n+1);
    FOR(i,0,n){
        FOR(j,0,n-1){
            printf("%d",ans[i][j]);
        }
        puts("");
    }
    return 0;
}