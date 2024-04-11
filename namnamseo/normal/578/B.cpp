#include <cstdio>

typedef long long ll;

ll data[200010];
int n,k,x;

int bitlen(ll x)
{
    int ret=0;
    while(x) x>>=1, ++ret;
    return ret;
}
int mi, ml;

ll cval, ans;
int cc[62];

ll max(ll a,ll b){ return a>b?a:b; }

void remove(ll x)
{
    int i;
    for(i=0;i<=62;++i){
        if(1&(x>>i)){
            --cc[i];
            if(cc[i]==0) cval -= (1ll<<i);
        }
    }
}

void add(ll x)
{
    int i;
    for(i=0;i<=62;++i){
        if(1&(x>>i)){
            ++cc[i];
            if(cc[i]==1) cval += (1ll<<i);
        }
    }
}

int main()
{
    ll mul=1;
    scanf("%d%d%d",&n,&k,&x);
    int i;
    for(i=0;i<k;++i) mul*=x;
    int c;
    for(i=0;i<n;++i) scanf("%I64d",data+i);
    for(i=0;i<n;++i) add(data[i]);
    for(i=0;i<n;++i)
    {
        remove(data[i]);
        add(data[i]*mul);
        ans=max(ans,cval);
        remove(data[i]*mul);
        add(data[i]);
    }
    printf("%I64d\n",ans);
    return 0;
}