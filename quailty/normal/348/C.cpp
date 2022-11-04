#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int BLOCK=335;
vector<int>s[MAXN],big;
int id[MAXN],vis[MAXN],t[BLOCK][MAXN];
ll a[MAXN],tag[BLOCK],sum[BLOCK];
int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int k;
        scanf("%d",&k);
        s[i].resize(k);
        for(int j=0;j<k;j++)
            scanf("%d",&s[i][j]);
        if(k>BLOCK)
        {
            id[i]=(int)big.size();
            big.push_back(i);
            for(int j=0;j<k;j++)
                sum[id[i]]+=a[s[i][j]];
        }
        else id[i]=-1;
    }
    for(int ii=0;ii<(int)big.size();ii++)
    {
        int i=big[ii];
        for(int j=0;j<(int)s[i].size();j++)
            vis[s[i][j]]=1;
        for(int k=1;k<=n;k++)
            for(int j=0;j<(int)s[k].size();j++)
                t[ii][k]+=vis[s[k][j]];
        for(int j=0;j<(int)s[i].size();j++)
            vis[s[i][j]]=0;
    }
    for(int i=1;i<=q;i++)
    {
        char ty[5];
        int k;
        scanf("%s%d",ty,&k);
        if(*ty=='?')
        {
            ll res=0;
            if(id[k]<0)
            {
                for(int j=0;j<(int)s[k].size();j++)
                    res+=a[s[k][j]];
                for(int j=0;j<(int)big.size();j++)
                    res+=t[j][k]*tag[j];
            }
            else
            {
                res+=sum[id[k]];
                for(int j=0;j<(int)big.size();j++)
                    res+=t[id[k]][big[j]]*tag[j];
            }
            printf("%lld\n",res);
        }
        else
        {
            ll x;
            scanf("%lld",&x);
            if(id[k]<0)
            {
                for(int j=0;j<(int)s[k].size();j++)
                    a[s[k][j]]+=x;
                for(int j=0;j<(int)big.size();j++)
                    sum[j]+=t[j][k]*x;
            }
            else tag[id[k]]+=x;
        }
    }
    return 0;
}