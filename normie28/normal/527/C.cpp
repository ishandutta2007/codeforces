#include <cstdio>
#include <cstdlib>
#include <algorithm> 
using namespace std;
#define lson id<<1
#define rson id<<1|1
const long long maxn=800010;
long long x,w,h,n,a[maxn],b[maxn];
char c;
long long lef[maxn][2],righ[maxn][2],l[maxn][2],r[maxn][2],ma[maxn][2];
bool pure[maxn][2];
void pushup(long long id,long long k){
    pure[id][k]=pure[lson][k]&&pure[rson][k];
    ma[id][k]=max(r[lson][k]+l[rson][k],max(ma[lson][k],ma[rson][k]));
    l[id][k]=pure[lson][k]?l[lson][k]+l[rson][k]:l[lson][k];
    r[id][k]=pure[rson][k]?r[rson][k]+r[lson][k]:r[rson][k];
}
inline void build(long long id,long long ll,long long rr,long long k)
{
    lef[id][k]=ll;righ[id][k]=rr;
    if (ll==rr){pure[id][k]=true;ma[id][k]=1;l[id][k]=1;r[id][k]=1;return;}
    long long mid=(ll+rr)>>1;
    build(lson,ll,mid,k);build(rson,mid+1,rr,k);
    pushup(id,k);
}
inline void update(long long id,long long x,long long k){
    if (lef[id][k]==x && righ[id][k]==x){pure[id][k]=false;ma[id][k]=0;l[id][k]=0;r[id][k]=0;return;}
    long long mid=(lef[id][k]+righ[id][k])>>1;
    if (x<=mid) update(lson,x,k);
    	   else update(rson,x,k);
    pushup(id,k);
}
int main(){
    scanf("%lld%lld%lld",&w,&h,&n);
    build(1,1,w-1,1);build(1,1,h-1,0);
    for (long long i=1;i<=n;i++)
    {   
        c=getchar();
        while (c!='H' && c!='V') c=getchar();
        if (c=='V') {scanf("%lld",&x);update(1,x,1);}
        else {scanf("%lld",&x);update(1,x,0);}
        printf("%lld\n",(ma[1][1]+1)*(ma[1][0]+1));
    }
    return 0;
}