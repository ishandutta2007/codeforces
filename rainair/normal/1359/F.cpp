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
#define ld long double
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
const ld EPS = 1e-8;

inline int sgn(ld x){
    if(std::fabs(x) <= EPS) return 0;
    if(x > 0) return 1;
    return -1;
}

struct Point{
    ld x,y;
    Point(ld x=0,ld y=0) : x(x),y(y) {}

    inline Point operator + (const Point &t) const {
        return Point(x+t.x,y+t.y);
    }

    inline Point operator - (const Point &t) const {
        return Point(x-t.x,y-t.y);
    }

    inline ld operator * (const Point &t) const {
        return x*t.y-y*t.x;
    }

    inline Point operator * (const ld &t) const {
        return Point(x*t,y*t);
    }

    inline bool operator == (const Point &t) const {
        return sgn(x-t.x)==0 && sgn(y-t.y) == 0;
    }
};

struct Seg{
    Point s,t;

    ld f(ld x){
        return s.y+(x-s.x)*(t.y-s.y)/(t.x-s.x);
    }

    friend bool operator < (Seg l1,Seg l2){//  set  
        ld t = std::max(l1.s.x,l2.s.x);
        ld y1 = l1.f(t),y2 = l2.f(t);
        if(sgn(y1-y2) == 0){
            if(sgn(l1.s.x-l2.s.x) == 0){
                return sgn(l1.t.x-l2.t.x) < 0;
            }
            return sgn(l1.s.x-l2.s.x) < 0;
        }
        return sgn(y1-y2) < 0;
    }
};

inline bool intersect(const Seg &l1,const Seg &l2){
    return std::max(l1.s.x,l1.t.x) >= std::min(l2.s.x,l2.t.x)
        && std::min(l1.s.x,l1.t.x) <= std::max(l2.s.x,l2.t.x)
        && std::max(l1.s.y,l1.t.y) >= std::min(l2.s.y,l2.t.y)
        && std::min(l1.s.y,l1.t.y) <= std::max(l2.s.y,l2.t.y)
        && sgn((l2.t-l2.s)*(l1.s-l2.s))*sgn((l2.t-l2.s)*(l1.t-l2.s)) <= 0
        && sgn((l1.t-l1.s)*(l2.s-l1.s))*sgn((l1.t-l1.s)*(l2.t-l1.s)) <= 0;
}

std::set<Seg> S;
int n;
int sx[MAXN],sy[MAXN],dx[MAXN],dy[MAXN],s[MAXN];
Seg a[MAXN];

struct Event{
    Seg t;ld x;int opt;

    bool operator < (const Event &tt) const {
        if(sgn(x-tt.x) == 0) return opt < tt.opt;
        return sgn(x-tt.x) < 0;
    }
};

inline bool chk(ld k){
    std::vector<Event> E;S.clear();
    FOR(i,1,n){
        ld len = std::sqrt((ld)(dx[i]*dx[i]+dy[i]*dy[i]));
        Seg t = (Seg){Point(sx[i],sy[i]),Point(sx[i]+1ll*dx[i]*s[i]*k/len,sy[i]+1ll*dy[i]*s[i]*k/len)};
        if(sgn(t.s.x-t.t.x) > 0) std::swap(t.s,t.t);
        E.pb((Event){t,t.s.x,1});E.pb((Event){t,t.t.x,-1});
    }
    std::sort(all(E));
    for(auto x:E){
        if(x.opt == 1){
            auto it = S.insert(x.t).fi;
            if(it != S.begin()){
                --it;
                if(intersect(x.t,*it)) return true;
                ++it;
            }
            ++it;
            if(it != S.end()){
                if(intersect(x.t,*it)) return true;
            }
        }
        if(x.opt == -1){
            auto it = S.find(x.t);auto l = it,r = it;
            --l;++r;
            if(it != S.begin() && r != S.end()){
                if(intersect(*l,*r)) return true;
            }
            S.erase(it);
        }
    }
    return false;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d%d%d%d",sx+i,sy+i,dx+i,dy+i,s+i);
    }
    ld l = 0,r = 1e12,ans = -1;
    FOR(i,1,60){
        ld mid = (l + r) / 2.0;
        if(chk(mid)) ans = mid,r = mid;
        else l = mid;
    }
    if(ans == -1) puts("No show :(");
    else printf("%.20lf\n",(double)ans);
    return 0;
}