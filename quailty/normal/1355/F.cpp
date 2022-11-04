#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXX=1000000000;
const ll MAXQ=1000000000000000000;

const int MAXN=1000;
int p[MAXN];
bool np[MAXN];
int cnt;
ll prod[MAXN];
vector<int> fac[MAXN];

void build()
{
    for(int i=2;i<MAXN;i++)
    {
        if(np[i])continue;
        p[++p[0]]=i;
        for(int j=i*i;j<MAXN;j+=i)np[j]=1;
    }
    prod[++cnt]=1;
    for(int i=1;i<=p[0];i++)
    {
        if(prod[cnt]<=MAXQ/p[i])
        {
            prod[cnt]*=p[i];
            fac[cnt].push_back(p[i]);
        }
        else prod[++cnt]=1;
    }
}

ll query(ll q)
{
    printf("? %lld\n",q);
    fflush(stdout);
    ll r;
    scanf("%lld",&r);
    return r;
}

void answer(int ans)
{
    printf("! %d\n",ans);
    fflush(stdout);
}

void Main()
{
    int que=22,res=1;
    for(int i=1;i<=cnt && que;i++)
    {
        ll r=query(prod[i]);
        que--;
        for(auto &p:fac[i])
            if(r%p==0 && que)
            {
                ll t=1;
                while(t<=MAXX)t*=p;
                t=query(t);
                que--;
                int cnt=0;
                while(t>1)cnt++,t/=p;
                res*=cnt+1;
            }
    }
    answer(res*2);
}

int main()
{
    build();
    int T;
    scanf("%d",&T);
    while(T--)Main();
    return 0;
}