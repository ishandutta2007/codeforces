#include <cstdio>
#include <algorithm>
using namespace std;
int n,q;
int xs[200010], xc;
int ys[200010], yc;
struct tree {
    int d[524288];
    tree(){
        int i;
        for(i=0;i<524288;++i) d[i]=2e9;
    }
    void upd(int pos,int val){
        pos+=262144;
        d[pos]=min(d[pos],val);
        pos/=2;
        while(pos){
            d[pos]=min(d[pos*2],d[pos*2+1]); pos/=2;
        }
    }
    int rangeMin(int l,int r){
        int ret=2e9;
        l+=262144; r+=262144;
        while(l<=r){
            if(l==r){
                ret=min(ret,d[l]); break;
            }
            if(l&1) ret=min(ret,d[l++]);
            if((r+1)&1) ret=min(ret,d[r--]);
            l/=2; r/=2;
        }
        return ret;
    }
    int findRightest(int l,int r,int x){
        if(l==r) return l;
        int m=(l+r)/2;
        if(rangeMin(m+1,r)<=x){
            return findRightest(m+1,r,x);
        } else return findRightest(l,m,x);
    }
} xt, yt;
int x     [200010];
int y     [200010];
bool eaten[200010];
char t    [200010];
int main()
{
    scanf("%d%d",&n,&q);
    int i;
    for(i=0;i<q;++i){
        scanf("%d %d %c",x+i,y+i,t+i);
        xs[i]=x[i]; ys[i]=y[i];
    }
    sort(xs,xs+q);
    sort(ys,ys+q);
    xc=unique(xs,xs+q)-xs;
    yc=unique(ys,ys+q)-ys;
    int xcmp, ycmp;
    int bef;
    for(i=0;i<q;++i){
        xcmp=lower_bound(xs,xs+xc,x[i])-xs;
        ycmp=lower_bound(ys,ys+yc,y[i])-ys;
        if(eaten[xcmp]){
            puts("0"); continue;
        }
        eaten[xcmp]=true;
        if(t[i]=='U'){
            if(yt.rangeMin(0,ycmp-1)<=xcmp){
                bef=yt.findRightest(0,ycmp-1,xcmp);
                printf("%d\n",ys[ycmp]-ys[bef]);
                xt.upd(xcmp,bef);
            } else {
                printf("%d\n",ys[ycmp]);
                xt.upd(xcmp,0);
            }
        } else {
            if(xt.rangeMin(0,xcmp-1)<=ycmp){
                bef=xt.findRightest(0,xcmp-1,ycmp);
                printf("%d\n",xs[xcmp]-xs[bef]);
                yt.upd(ycmp,bef);
            } else {
                printf("%d\n",xs[xcmp]);
                yt.upd(ycmp,0);
            }
        }
    }
    return 0;
}