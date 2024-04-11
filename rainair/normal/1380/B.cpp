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
const int MAXN = 5e6 + 5;
char str[MAXN];
int cnt[233];
inline void Solve(){
    CLR(cnt,0);
    scanf("%s",str+1);int n = strlen(str+1);
    FOR(i,1,n) cnt[str[i]]++;
    int mx = -1e9,ps = 0;
    FOR(i,0,232) if(mx < cnt[i]) mx = cnt[i],ps = i;
    if(ps == 'P'){
        FOR(i,1,n) putchar('S');
    }
    if(ps == 'R'){
        FOR(i,1,n) putchar('P');
    }
    if(ps == 'S'){
        FOR(i,1,n) putchar('R');
    }puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}