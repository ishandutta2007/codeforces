#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int MAXM=100005;
const int Mod=1000000009;
map<pair<int,int>,int> id;
pair<int,int> loc[MAXM];
set<int>u;
bool judge(int x,int y,int d)
{
    if(id.find(make_pair(x,y))==id.end())return 1;
    for(int i=-1;i<=1;i++)
    {
        if(i==d)continue;
        if(id.find(make_pair(x+i,y-1))!=id.end())return 1;
    }
    return 0;
}
void modify(int x,int y)
{
    if(id.find(make_pair(x,y))==id.end())return;
    bool isok=1;
    for(int i=-1;i<=1;i++)
    {
        isok&=judge(x+i,y+1,-i);
    }
    int now=id[make_pair(x,y)];
    if(isok)u.insert(now);
    else u.erase(now);
}
int main()
{
    int m;
    scanf("%d",&m);
    int x,y;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        id[make_pair(x,y)]=i;
        loc[i]=make_pair(x,y);
    }
    for(int i=0;i<m;i++)
    {
        bool isok=1;
        for(int j=-1;j<=1;j++)
        {
            isok&=judge(loc[i].first+j,loc[i].second+1,-j);
        }
        if(isok)u.insert(i);
    }
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        int c;
        /*
        for(set<int>::iterator itr=u.begin();itr!=u.end();itr++)
        {
            printf("%d ",*itr);
        }
        printf("\n");
        */
        if(i&1)c=*u.begin();
        else c=*u.rbegin();
        ans=(ans*m+c)%Mod;
        id.erase(loc[c]);
        u.erase(c);
        for(int j=-2;j<=2;j++)
            for(int k=-2;k<=2;k++)
                modify(loc[c].first+j,loc[c].second+k);
    }
    printf("%I64d\n",ans);
    return 0;
}