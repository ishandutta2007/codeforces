/*
 * Author: RainAir
 * Time: 2019-10-09 09:53:22
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
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;

struct Point{
    double x,y;int id;
    Point(double x=0,double y=0,int id=0) : x(x),y(y),id(id) {}
}p0[MAXN],p1[MAXN];
int n,k;

inline bool chk(int a,int b,int c,int d){
    std::set<int> S;
    if(p1[a+1].y < p1[n-b].y || p0[c+1].x > p0[n-d].x) return false;
    FOR(i,1,a) S.insert(p1[i].id);
    ROF(i,n,n-b+1) S.insert(p1[i].id);
    FOR(i,1,c) S.insert(p0[i].id);
    ROF(i,n,n-d+1) S.insert(p0[i].id);
    return S.size() <= k;
}

signed main(){
    scanf("%lld%lld",&n,&k);
    FOR(i,1,n){
        int x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        p0[i] = p1[i] = Point((x1+x2)/2.0,(y1+y2)/2.0,i);
    }
    std::sort(p0+1,p0+n+1,[](const Point &a,const Point &b) -> bool{
              return a.x < b.x;
              });
    std::sort(p1+1,p1+n+1,[](const Point &a,const Point &b) -> bool{
              return a.y > b.y;
              });
    LL ans = 1e18;
    FOR(a,0,k){
        FOR(b,0,k){
            FOR(c,0,k){
                FOR(d,0,k){
                    if(!chk(a,b,c,d)) continue;
                    double up = p1[a+1].y,down = p1[n-b].y;
                    double lft = p0[c+1].x,rit = p0[n-d].x;
                    int a = (up-down+0.5),b = (rit-lft+0.5);
                    if(!a) a = 1;
                    if(!b) b = 1;
                    ans = std::min(ans,a*b);
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}