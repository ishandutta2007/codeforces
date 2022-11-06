#include <cstdio>
#include <algorithm>

using namespace std;

int sqn;
int n;

struct p {
    int x,y,oi;
    bool operator<(const p&other)const{
        if(x/sqn==other.x/sqn){
            if((x/sqn)&1) return y<other.y;
            else return y>other.y;
        } else return x<other.x;
    }
} dat[1000010];

int abs(int x){ return x>0?x:-x; }

void work()
{
    sort(dat,dat+n);
    int i;
    for(i=0;i<n;++i) printf("%d ",dat[i].oi);
}

int main()
{
    scanf("%d",&n);
    int l=0, r=46340, m;
    while(l+1<r){
        m=(l+r)/2;
        if(m*m<=n) l=m; else r=m;
    }
    sqn=l;
    int i;
    for(i=0;i<n;++i) scanf("%d%d",&dat[i].x,&dat[i].y), dat[i].oi=i+1;
    work();
    return 0;
}