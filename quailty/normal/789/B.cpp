#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll,int> bad,vis;
int main()
{
    ll b,q,l,m,r=0;
    scanf("%lld%lld%lld%lld",&b,&q,&l,&m);
    for(ll i=1,a;i<=m;i++)
    {
        scanf("%lld",&a);
        bad[a]=1;
    }
    while(abs(b)<=l && vis[b]<2)
    {
        vis[b]++;
        if(bad.find(b)==bad.end())r++;
        b*=q;
    }
    if(abs(b)<=l)for(auto itr=vis.begin();itr!=vis.end();itr++)
        if(itr->second>=2 && bad.find(itr->first)==bad.end())return 0*printf("inf");
    return 0*printf("%lld",r);
}