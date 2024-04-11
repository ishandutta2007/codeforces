#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int d[MAXN],a[MAXN];
vector<int>e[MAXN];
vector<pair<int,int> >v;
bool check(int m,int d)
{
    v.clear();
    for(int i=1;i<=m;i++)
    {
        int id=upper_bound(e[i].begin(),e[i].end(),d)-e[i].begin()-1;
        if(id<0)return 0;
        v.push_back(make_pair(e[i][id],i));
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<(int)v.size();i++)
    {
        sum+=a[v[i].second];
        if(sum>=v[i].first)return 0;
        sum++;
    }
    return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        if(d[i])e[d[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    int tl=1,tr=n+1;
    while(tl<tr)
    {
        int tm=(tl+tr)/2;
        if(check(m,tm))tr=tm;
        else tl=tm+1;
    }
    printf("%d\n",(tl<=n ? tl : -1));
    return 0;
}