#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100000;
const int MAXF=7005;
vector<ll>d;
vector<int>f[MAXF];
vector<int>cal(ll k)
{
    if(k==0)return vector<int>(1,(int)d.size()-1);
    if(k==1)return f[(int)d.size()-1];
    vector<int>now;
    if(k&1)now=cal(k-1);
    else
    {
        now=cal(k/2);
        vector<int>vis(d.size(),(int)now.size()-1);
        for(int i=0;i<(int)now.size();i++)
            vis[now[i]]=min(vis[now[i]],i);
        vector<int>tmp;
        for(int i=0;i<(int)now.size();i++)
        {
            int l=(now[i] ? vis[now[i]-1]+1 : 0);
            int r=vis[now[i]];
            for(int j=l;j<=r && (int)tmp.size()<MAXN;j++)
                tmp.push_back(now[j]);
        }
        now=tmp;
    }
    vector<int>res;
    for(int i=0;i<(int)now.size();i++)
        for(int j=0;j<(int)f[now[i]].size() && (int)res.size()<MAXN;j++)
            res.push_back(f[now[i]][j]);
    return res;
}
int main()
{
    ll x,k;
    scanf("%lld%lld",&x,&k);
    for(ll i=1;i*i<=x;i++)if(x%i==0)
    {
        d.push_back(i);
        if(i*i!=x)d.push_back(x/i);
    }
    sort(d.begin(),d.end());
    for(int i=0;i<(int)d.size();i++)
        for(int j=0;j<=i;j++)
            if(d[i]%d[j]==0)f[i].push_back(j);
    vector<int>res=cal(k);
    for(int i=0;i<(int)res.size();i++)
        printf("%lld ",d[res[i]]);
    return 0;
}