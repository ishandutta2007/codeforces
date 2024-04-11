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
const double EPS = 1e-8;

inline int sgn(double x){
    if(std::fabs(x) <= EPS) return 0;
    return x > 0 ? 1 : -1;
}

struct Node{
    double x,y;
    Node(double x=0,double y=0) : x(x),y(y) {}

    Node operator + (const Node &t) const {
        return Node(x+t.x,y+t.y);
    }

    Node operator * (const double &t) const {
        return Node(x*t,y*t);
    }

    double operator * (const Node &t) const {
        return x*t.y-y*t.x;
    }
}a[MAXN],p[MAXN];

int n,q;

struct Event{
    double x,k,b;int id;
    Event(double x=0,double k=0,double b=0,int id=0) : x(x),k(k),b(b),id(id) {}

    inline bool operator < (const Event &t) const {
        if(sgn(x-t.x)) return sgn(x-t.x) < 0;
        return id < t.id;
    }
};
std::vector<Event> v;

inline void add(Node A,Node B,int t){
    if(!sgn(A.x-B.x)) return;
    if(A.x > B.x) std::swap(A,B),t = -t;
    double k = (B.y-A.y)/(B.x-A.x),b = A.y-A.x*k;
    v.pb(Event(A.x,t*k,t*b,0));v.pb(Event(B.x,-t*k,-t*b,0));
}

inline Node rej(Node A,Node B,Node p){
    return Node(A.x+(B.x-A.x)*(p.y-A.y)/(B.y-A.y),p.y);
}

double ans[MAXN];

int main(){
    scanf("%d%d",&n,&q);
    int mn = 0;
    FOR(i,0,n-1){
        scanf("%lf%lf",&a[i].x,&a[i].y);
        if(a[i].y < a[mn].y) mn = i;
    }
    int _ = -1;
    FOR(i,mn,n-1) p[++_] = a[i];
    FOR(i,0,mn-1) p[++_] = a[i];
    double area = 0;
    FOR(i,0,n-1){
        area += p[i]*p[(i+1)%n];
        if(p[i].y > p[(i+1)%n].y) add(p[i],p[(i+1)%n],1);
        else add(p[(i+1)%n],p[i],1);
    }
    area = std::fabs(area*0.5);
    DEBUG(area);
    Node mid = p[0],mid2;int L = 0,R = 0;
    FOR(i,0,n-2){
        int L2 = (L+1)%n,R2 = (R+n-1)%n;
        if(p[L2].y < p[R2].y){
            mid2 = (p[L2]+rej(p[R],p[R2],p[L2]))*0.5;
            L = L2;
        }
        else{
            mid2 = (p[R2]+rej(p[L],p[L2],p[R2]))*0.5;
            R = R2;
        }
        add(mid,mid2,2);mid = mid2;
    }
    FOR(i,1,q){
        int x;scanf("%d",&x);
        v.pb(Event(x,0,0,i));
    }
    std::sort(all(v));double k=0,b=0;
    for(auto x:v){
        if(x.id){
            ans[x.id] = area+0.5*x.x*x.x*k+x.x*b;
        }
        else{
            area -= 0.5*x.x*x.x*x.k+x.x*x.b;
            k += x.k;b += x.b;
        }
    }
    FOR(i,1,q) printf("%.10f\n",ans[i]);
    return 0;
}