#include <cstdio>
#include <algorithm>

using namespace std;

struct stick {
    int l,d;
} d[100010];

int cuont[201];

int n;

int main()
{
    scanf("%d",&n);
    int i,j, ds=0;
    int ans=0, cs=0, cc, cic=0, cds=0, use;
    for(i=1;i<=n;++i) scanf("%d",&d[i].l);
    for(i=1;i<=n;++i) scanf("%d",&d[i].d), ds+=d[i].d, ans=max(ans,d[i].d);
    sort(d+1,d+n+1,[](const stick& a,const stick& b){return (a.l==b.l)?(a.d>b.d):(a.l<b.l);});
    for(i=1;i<=n;++i){
        ++cic;
        cs=cc=0;
        cds+=d[i].d;
        for(j=200;j>=1 && cc<cic-1;--j){
            use = min(cuont[j],(cic-1)-cc);
            cs+=use*j;
            cc+=use;
        }
        ans=max(ans,cs+cds);
        if(i!=n && d[i].l != d[i+1].l) {
            for(j=i;1<=j && d[j].l==d[i].l;--j) ++cuont[d[j].d];
            cic=cds=0;
        }
    }
    printf("%d\n",ds-ans);
    return 0;
}