/*
 * Author: RainAir
 * Time: 2020-05-28 22:58:56
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

const int MAXN = 5e5 + 5;
const int MAXM = 17;
int a[MAXN],sm[MAXN];
int n;
int pre[MAXN],suf[MAXN];
int now[2333];

int mx[MAXM+1][MAXN],mn[MAXM+1][MAXN],pc[MAXN];
inline int calc1(int l,int r){
    int c = pc[r-l+1];
    return std::max(mx[c][l],mx[c][r-(1<<c)+1]);
}
inline int calc2(int l,int r){
    int c = pc[r-l+1];
    return std::min(mn[c][l],mn[c][r-(1<<c)+1]);
}

int main(){
    pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
    scanf("%d",&n);    CLR(mx,-0x3f);CLR(mn,0x3f);
    FOR(i,1,n) scanf("%d",a+i),sm[i] = sm[i-1]+a[i],mx[0][i] = mn[0][i] = sm[i];//,DEBUG(sm[i]);
    FOR(i,1,MAXM){
        for(int j = 1;j+(1<<(i-1)) < MAXN;++j){
            mx[i][j] = std::max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
            mn[i][j] = std::min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
        }
    }
    FOR(i,1,n){
        pre[i] = 0;
        FOR(j,a[i]+1,30){
            pre[i] = std::max(pre[i],now[j+30]);
        }
        now[a[i]+30] = i;
    }
    FOR(i,0,2332) now[i] = n+1;
    ROF(i,n,1){
        suf[i] = n+1;
        FOR(j,a[i]+1,30){
            suf[i] = std::min(suf[i],now[j+30]);
        }
        now[a[i]+30] = i;
    }
    int ans = 0;
    FOR(i,1,n){
        int l = pre[i]+1,r = suf[i]-1;
        if(l <= i-1) ans = std::max(ans,calc1(i,r)-std::min(calc2(l,i-1),l==1?0:1000000000)-a[i]);
        if(i+1 <= r) ans = std::max(ans,calc1(i+1,r)-std::min(calc2(l,i),l==1?0:1000000000)-a[i]);
    }
    printf("%d\n",ans);
    return 0;
}