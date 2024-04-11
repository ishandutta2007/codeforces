#include <bits/stdc++.h>
#define maxn 200200
typedef long long ll;
using namespace std;

struct point {
    ll x,y;
    point(ll x=0,ll y=0): x(x), y(y) {}
    point operator-(point p){
        return point(x-p.x,y-p.y);
    }
    long double norm(){
        return sqrt(x*x+y*y);
    }
    void rd(){
        scanf("%lld%lld",&x,&y);
    }
};

long double dist(point a,point b){
    return (a-b).norm();
}

point v[maxn];

long double cost[maxn];
long double wa[maxn];
long double wb[maxn];

int main() {
    point pa,pb,bin;
    pa.rd();
    pb.rd();
    bin.rd();
    int n;
    scanf("%d",&n);
    int b1,b2;
    long double tb1,tb2;
    tb1 = tb2 = -1e18;
    for(int i=0;i<n;i++){
        v[i].rd();
        cost[i] = 2.0 * dist(bin,v[i]);
        wa[i] = dist(bin,v[i]) - dist(pa,v[i]);
        wb[i] = dist(bin,v[i]) - dist(pb,v[i]);
        if(wb[i] > tb1){
            tb2 = tb1;
            b2 = b1;
            tb1 = wb[i];
            b1 = i;
        }
        else if(wb[i] > tb2){
            tb2 = wb[i];
            b2 = i;
        }
    }
    
    long double ans = 1e18;
    
    long double sd = 0;
    for(int i=0;i<n;i++)
        sd += cost[i];
    
    for(int i=0;i<n;i++){
        ans = min(ans,sd-wa[i]);
        ans = min(ans,sd-wb[i]);
        long double u = tb1;
        if(b1 == i) u = tb2;
        ans = min(ans,sd-wa[i]-u);
    }
    
    printf("%lf\n",(double)ans);
    
}