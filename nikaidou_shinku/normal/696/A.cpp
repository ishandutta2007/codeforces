#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll,ll>mp;
int dep(ll x)
{
    int res=-1;
    while(x)
    {
        res++;
        x>>=1;
    }
    return res;
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int ty;
        scanf("%d",&ty);
        if(ty==1)
        {
            ll v,u,w;
            scanf("%I64d%I64d%I64d",&v,&u,&w);
            int dv=dep(v),du=dep(u);
            if(du<dv)swap(u,v),swap(du,dv);
            ll tu=u,tv=v;
            for(int i=0;i<du-dv;i++)tu>>=1;
            while(tu!=tv)
            {
                tu>>=1;
                tv>>=1;
            }
            while(u!=tu)
            {
                mp[u]+=w;
                u>>=1;
            }
            while(v!=tv)
            {
                mp[v]+=w;
                v>>=1;
            }
        }
        else
        {
            ll v,u,res=0;
            scanf("%I64d%I64d",&v,&u);
            int dv=dep(v),du=dep(u);
            if(du<dv)swap(u,v),swap(du,dv);
            ll tu=u,tv=v;
            for(int i=0;i<du-dv;i++)tu>>=1;
            while(tu!=tv)
            {
                tu>>=1;
                tv>>=1;
            }
            while(u!=tu)
            {
                res+=(mp.find(u)!=mp.end() ? mp[u] : 0);
                u>>=1;
            }
            while(v!=tv)
            {
                res+=(mp.find(v)!=mp.end() ? mp[v] : 0);
                v>>=1;
            }
            printf("%I64d\n",res);
        }
    }
    return 0;
}