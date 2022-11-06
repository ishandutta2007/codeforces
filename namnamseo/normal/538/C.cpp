#include <cstdio>

typedef long long ll;

int n,m;

ll day[100010];
ll hei[100010];

ll abs(ll x) { return x>0?x:-x; }

ll max(ll a,ll b) { return a>b?a:b; }

int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<m;++i) scanf("%I64d%I64d",day+i,hei+i);
    ll ans=0;
    for(i=0;i<m-1;++i){
        ans=max(ans,hei[i+1]);
        if(day[i+1]-day[i]<abs(hei[i+1]-hei[i])){
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    ll tmp;
    for(i=0;i<m-1;++i){
        tmp=day[i+1]+hei[i+1]+day[i]-hei[i];
        ans=max(ans,tmp/2-day[i]+hei[i]);
    }
    ans=max(ans,day[0]-1+hei[0]);
    ans=max(ans,n-day[m-1]+hei[m-1]);
    printf("%I64d\n",ans);
    return 0;
}