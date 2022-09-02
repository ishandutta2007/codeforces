#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef double ld;

const ld eps=1e-9;

struct point{
    int x,y;    
    point(){};
    point(int x,int y):x(x),y(y){};
};

struct dpoint{
    ld x,y;
    dpoint(){};
    dpoint(ld x,ld y):x(x),y(y){};
    dpoint(point a){    
        x=a.x;
        y=a.y;
    }
    bool operator<(const dpoint& a) const{
        if (abs(x-a.x) > eps)
            return x < a.x;
        return y < a.y - eps;
    }
};



struct segment{
    point p1,p2;
    segment(){};
    segment(const point& P1,const point& P2){
        p1=P1;
        p2=P2;
    }   
};

struct line{
    int a,b;
    int64 c;
    line(){};
    line(const point& p1,const point& p2){
        a=p1.y-p2.y;
        b=p2.x-p1.x;
        c=-p1.x*1LL*a-p1.y*1LL*b;
    }
    line(const segment& s){
        a=s.p1.y-s.p2.y;
        b=s.p2.x-s.p1.x;
        c=-s.p1.x*1LL*a-s.p1.y*1LL*b;       
    }
    int side(const point& p){
        int64 tmp=a*1LL*p.x+b*1LL*p.y+c;
        if (tmp < 0)
            return -1;
        if (tmp > 0)
            return 1;
        return 0;
    }
};

bool isintersec(const segment& a,const segment& b){
    line l(a);
    if (l.side(b.p1) * l.side(b.p2) != -1)
        return 0;
    line l1(b);
    if (l1.side(a.p1) * l1.side(a.p2) != -1)
        return 0;
    return 1;
}

ld det (ld a, ld b, ld c, ld d) {
    return a * d - b * c;
}
 
dpoint intersec (line m, line n) {
    dpoint res;
    ld zn = det (m.a, m.b, n.a, n.b);
    res.x = - det (m.c, m.b, n.c, n.b) / zn;
    res.y = - det (m.a, m.c, n.a, n.c) / zn;
    return res;
}

point t[110][3];
int n;

ld dest(const dpoint& a,const dpoint& b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

dpoint operator-(dpoint a,dpoint b){
    return dpoint(a.x-b.x,a.y-b.y);
}

point operator-(point a,point b){
    return point(a.x-b.x,a.y-b.y);
}


dpoint operator+(dpoint a,dpoint b){
    return dpoint(a.x+b.x,a.y+b.y);
}


dpoint operator/(dpoint a,int b){
    return dpoint(a.x/b,a.y/b);
}


ld operator*(const dpoint& a,const dpoint& b){
    return a.x*b.y-a.y*b.x;
}

int64 operator*(const point& a,const point& b){
    return a.x*1LL*b.y-a.y*1LL*b.x;
}


bool check(const dpoint& p,const point& a,const point& b,const point& c){
    int64 s=abs((b-a)*(c-a));
    ld s1=abs((a-p)*(b-p));
    ld s2=abs((a-p)*(c-p));
    ld s3=abs((b-p)*(c-p));
    if (s1 < (1e-2))    return false;
    if (s2 < (1e-2))    return false;
    if (s3 < (1e-2))    return false;
    if (abs(s-s1-s2-s3)<eps*max(1LL,s))
        return true;
    return false;
}

bool check(dpoint p){
    for (int i=0;i<n;i++)
        if (check(p,t[i][0],t[i][1],t[i][2]))
            return false;
    return true;
}


ld ans;

void solve(const segment& s){
    vector<dpoint> p;
    p.pb(dpoint(s.p1.x,s.p1.y));
    p.pb(dpoint(s.p2.x,s.p2.y));
    for (int i=0;i<n;i++)
        for (int j=0;j<3;j++){
            segment tmp(t[i][j],t[i][(j+1)%3]);
            if (isintersec(s,tmp))
                p.pb(intersec(line(s),line(tmp)));
        }
    sort(p.begin(),p.end());
    
    for (int i=0;i+1<p.size();i++){
        if (check((p[i]+p[i+1])/2))
            ans+=dest(p[i],p[i+1]);
    }       
}








int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<3;j++)
            scanf("%d %d",&t[i][j].x,&t[i][j].y);
    
    for (int i=0;i<n;i++)
        for (int j=0;j<3;j++)
            solve(segment(t[i][j],t[i][(j+1)%3]));
    
    cout.precision(15);
    cout<<fixed<<ans<<endl;
  
    return 0;
}