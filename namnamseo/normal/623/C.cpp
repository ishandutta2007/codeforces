#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

//inline int max(int a,int b){ return a>b?a:b; }
//inline int min(int a,int b){ return a>b?b:a; }

inline int abs(int a){ return a>0?a:-a; }

inline ll sqr(ll x){ return x*x; }

ll ans=~(1ull<<63);

struct point {
    int x,y;
    int comp_y;
} d[100010];

int ys[100010], yn;
int xs[100010], xn;
int n;

int maxy_l[100010];
int miny_l[100010];

int maxy_r[100010];
int miny_r[100010];

bool can(ll D){
    int i;
    int left_ind=1, right_ind=1;
    for(i=0; i<xn; ++i){
        int curx = xs[i];
        
        while(d[left_ind].x < curx) ++left_ind;
        while(right_ind+1 <= n && sqr(d[right_ind+1].x-curx) <= D) ++right_ind;
        
        int max_y = max(0, max(maxy_l[left_ind-1], maxy_r[right_ind+1]));
        int min_y = min(0, min(miny_l[left_ind-1], miny_r[right_ind+1]));
        
        int max_x = d[right_ind].x;
        int min_x = curx;
        
        if(1<left_ind || right_ind<n) max_x=max(0,max_x), min_x=min(0,min_x);
        
        //printf("left %d right %d\n",left_ind,right_ind);
        //printf("x %d~%d, %d~%d\n",min_x,max_x,min_y,max_y);
        
        if(sqr(max_x-min_x)>D || sqr(max_y-min_y)>D) continue;
        
        if(1==left_ind && right_ind==n) return true;
        
        int max_absx = max(abs(max_x), abs(min_x));
        int max_absy = max(abs(max_y), abs(min_y));
        
        //printf("Max absx %d, %d\n",max_absx,max_absy);
        
        if(sqr(max_absx)+sqr(max_absy)<=D) return true;
    }
    return false;
}

void work(){
    int i;
    for(i=1;i<=n;++i){
        xs[i-1]=d[i].x;
        ys[i-1]=d[i].y;
    }
    sort(ys,ys+n); yn=unique(ys,ys+n)-ys;
    sort(xs,xs+n); xn=unique(xs,xs+n)-xs;
    
    for(i=1;i<=n;++i) d[i].comp_y = lower_bound(ys,ys+yn,d[i].y)-ys;
    
    sort(d+1,d+n+1,[](const point& a,const point& b){ return a.x<b.x; });
    
    maxy_l[1]=d[1].y;
    miny_l[1]=d[1].y;
    for(i=2;i<=n;++i) 
        maxy_l[i]=max(maxy_l[i-1],d[i].y),
        miny_l[i]=min(miny_l[i-1],d[i].y);
    
    maxy_r[n]=d[n].y;
    miny_r[n]=d[n].y;
    for(i=n-1;i>=1;--i) 
        maxy_r[i]=max(maxy_r[i+1],d[i].y),
        miny_r[i]=min(miny_r[i+1],d[i].y);
    
    maxy_l[0]=maxy_r[n+1]=-2147483648;
    miny_l[0]=miny_r[n+1]= 2147483647;
    
    
    ll l=0, r=~(1ull<<63), m;
    if(can(0)){ ans=0;  return; }
    
    while(l+1<r){
        m=(l+r)/2;
        if(can(m)) r=m;
        else l=m;
    }
    
    ans=min(ans,r);
}

int main() {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        scanf("%d%d",&d[i].x,&d[i].y);
    }
    
    work();
    for(i=1;i<=n;++i) d[i].x=-d[i].x;
    work();
    for(i=1;i<=n;++i) swap(d[i].x,d[i].y);
    work();
    for(i=1;i<=n;++i) d[i].x=-d[i].x;
    work();
    
            
    printf("%I64d\n",ans);
    
    return 0;
}