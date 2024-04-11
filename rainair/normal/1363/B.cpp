/*
 * Author: RainAir
 * Time: 2020-06-01 15:00:12
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

const int MAXN = 1e5 + 5;
char str[MAXN];
int sm0[MAXN],sm1[MAXN];

inline void Solve(){
    scanf("%s",str+1);int n = strlen(str+1);
    FOR(i,1,n){
        sm0[i] = sm0[i-1];sm1[i] = sm1[i-1];
        if(str[i] == '0') sm0[i]++;
        else sm1[i]++;
    }
    int ans = 1e9;
    FOR(i,1,n){
        ans = std::min(ans,std::min(sm0[i]+sm1[n]-sm1[i],sm1[i]+sm0[n]-sm0[i]));
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}