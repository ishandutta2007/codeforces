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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 500+5;

struct point{double x,y;int ix,iy;}p[MAXN];
struct line{point a,b;};

point intersection(line u,line v){
    point ret=u.a;
    double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
        /((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x+=(u.b.x-u.a.x)*t;
    ret.y+=(u.b.y-u.a.y)*t;
    return ret;
}

point calc(point a,point b,point c){
    line u,v;
    u.a.x=(a.x+b.x)/2;
    u.a.y=(a.y+b.y)/2;
    u.b.x=u.a.x-a.y+b.y;
    u.b.y=u.a.y+a.x-b.x;
    v.a.x=(a.x+c.x)/2;
    v.a.y=(a.y+c.y)/2;
    v.b.x=v.a.x-a.y+c.y;
    v.b.y=v.a.y+a.x-c.x;
    return intersection(u,v);
}

inline double dis2(const point &a,const point &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

inline double dis(const point &a,const point &b){
    return std::sqrt(dis2(a,b));
}

int n;
std::map<P,int> S;

double upd(const point &x){
    double res = 1e18;
    FOR(i,1,n) res = std::min(res,dis(x,p[i]));
    return res;
}
using std::abs;
const double EPS = 1e-10;
#define p(x) ((x)*(x))
int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x,y;scanf("%d%d",&x,&y);
        S[MP(x,y)] = 1;p[i] = (point){x,y,x,y};
    }
    double ans = 0.0;
    FOR(i,1,n){
        FOR(j,i+1,n){
            FOR(k,j+1,n){
                LL a2 = dis2(p[i],p[j]),b2 = dis2(p[i],p[k]),c2 = dis2(p[k],p[j]);
                //  !=  !!!!!!!!!
                double a = dis(p[i],p[j]),b = dis(p[i],p[k]),c = dis(p[k],p[j]);
                bool flag = true;point t;double x=0.0,y=0.0;
                if(abs(a-b) <= EPS && abs(p(c)-p(a)-p(b)) <= EPS && S[MP(p[j].ix+p[k].ix-p[i].ix,p[j].iy+p[k].iy-p[i].iy)]) x = (p[j].x+p[k].x)/2.0,y = (p[j].y+p[k].y)/2.0;
                else if(abs(a-c) <= EPS && abs(p(b)-p(a)-p(c)) <= EPS && S[MP(p[i].ix+p[k].ix-p[j].ix,p[i].iy+p[k].iy-p[j].iy)]) x = (p[i].x+p[k].x)/2.0,y = (p[i].y+p[k].y)/2.0;
                else if(abs(b-c) <= EPS && abs(p(a)-p(b)-p(c)) <= EPS && S[MP(p[j].ix+p[i].ix-p[k].ix,p[j].iy+p[i].iy-p[k].iy)]) x = (p[j].x+p[i].x)/2.0,y = (p[j].y+p[i].y)/2.0;
                else flag = false;
                t = (point){x,y};
                if(flag){
                    double res = upd(t);
                    if(abs(res-dis(t,p[i])) <= EPS || res - dis(t,p[i]) > EPS) ans = std::max(ans,dis(t,p[i]));
                    continue;
                }
                double max = std::max(a2,std::max(b2,c2)),max2 = std::max(a,std::max(b,c));
                //if(a2+b2+c2 <= 2.0*max) continue;// 
                if(a2+b2+c2-2.0*max < EPS || abs(a2+b2+c2-2.0*max) <= EPS) continue;
                if(a+b+c-max2*2 < EPS || abs(a+b+c-max2*2) <= EPS) continue;
                t = calc(p[i],p[j],p[k]);
                //ans = std::max(ans,std::min(dis(t,p[i]),upd(t)));
                double res = upd(t);
                if(abs(res-dis(t,p[i])) <= EPS || res - dis(t,p[i]) > EPS) ans = std::max(ans,dis(t,p[i]));
            }
        }
    }
    if(ans == 0) puts("-1");
    else printf("%.10f\n",ans);
    return 0;
}