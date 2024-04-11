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

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
int x[MAXN],y[MAXN],a[MAXN],b[MAXN];
int N;
#define P std::pair<int,int>
#define MP std::make_pair
std::map<P,int> S,vis;

inline bool check(int ii,int j,int xx,int yy){
    vis.clear();
    vis[MP(a[j],b[j])]++;
    FOR(i,1,N){
        if(i == ii) continue;
        P t = MP(xx-x[i],yy-y[i]);
        if(S[t] <= vis[t]) return false;
        vis[t]++;
    }
    return true;
}

int main(){
    scanf("%d",&N);
    FOR(i,1,N) scanf("%d%d",x+i,y+i);
    FOR(i,1,N) scanf("%d%d",a+i,b+i);
    FOR(i,1,N) S[MP(a[i],b[i])]++;
    FOR(i,1,N){
        FOR(j,1,N){
            int xx = x[i]+a[j],yy = y[i]+b[j];
            if(check(i,j,xx,yy)){
                printf("%d %d\n",xx,yy);
                return 0;
            }
        }
    }
    return 0;
}