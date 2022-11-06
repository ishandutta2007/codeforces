#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int fa[26],dis[26],rt[26];
char s[26+5],t[26+5];
int Find(int x)
{
    if(x==fa[x])return x;
    int t=Find(fa[x]);
    dis[x]+=dis[fa[x]];
    return fa[x]=t;
}
void Union(int u,int v,int w)
{
    int fu=Find(u),fv=Find(v);
    if(fu!=fv)
    {
        int t=dis[u]-dis[v]+w;
        if(t>=0)fa[fv]=fu,dis[fv]=t;
        else fa[fu]=fv,dis[fu]=-t;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<26;i++)
        fa[i]=i,rt[i]=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int len=strlen(s);
        rt[s[0]-'a']=0;
        for(int j=1;j<len;j++)
        {
            rt[s[j]-'a']=0;
            Union(s[0]-'a',s[j]-'a',j);
        }
    }
    for(int i=0;i<26;i++)
        if(rt[i]>=0)rt[i]=Find(i);
    int now=0;
    for(int i=0;i<26;i++)
    {
        int cnt=0;
        for(int j=0;j<26;j++)
            if(rt[j]==i)
            {
                t[now+dis[j]]='a'+j;
                cnt++;
            }
        now+=cnt;
    }
    printf("%s",t);
    return 0;
}