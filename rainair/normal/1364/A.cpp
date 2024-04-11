/*
 * Author: RainAir
 * Time: 2020-06-14 14:40:49
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
int n,a[MAXN],x;
int sm[MAXN];
std::map<int,int> S;

inline void Solve(){
    scanf("%d%d",&n,&x);
    FOR(i,1,n) scanf("%d",a+i),sm[i] = (sm[i-1]+a[i])%x;
    int ans = -1;
    int las = n+1;
    FOR(i,1,n){
        if(sm[i]){
            las = i;break;
        }
    }
    FOR(i,1,n){
        if(sm[i]) ans = std::max(ans,i);
        else{
            ans = std::max(ans,i-las);
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}