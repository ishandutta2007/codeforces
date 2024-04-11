#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 300 + 5;
const double EPS = 1e-10;

struct Point{
    double x,y;
}p[MAXN];

double cross(Point p1,Point p2,Point p0){
    return ((p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x))*0.5;
}


int N;

int main(){
    scanf("%d",&N);
    FOR(i,1,N){
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    double ans = 0.0,l = 0.0,r = 0.0;
    FOR(i,1,N){
        FOR(j,i+1,N){
            l = r = 0.0;
            FOR(k,1,N){
                if(k == i or k == j) continue;
                double s = cross(p[i],p[j],p[k]);
                if(s < EPS) l = std::max(l,-s);
                else r = std::max(r,s);
            }
            if(not l or not r) continue;
            ans = std::max(ans,(l+r));
        }
    }
    printf("%.6f\n",ans);
    return 0;
}