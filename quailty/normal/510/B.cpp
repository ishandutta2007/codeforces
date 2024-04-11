#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[55][55];
int par[2505];
void Init(int cnt)
{
    for(int i=0;i<cnt;i++)par[i]=i;
}
int Find(int x)
{
    return par[x]==x ? x : par[x]=Find(par[x]);
}
void Union(int x,int y)
{
    par[x]=y;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    Init(n*m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    bool isok=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i>0 && s[i][j]==s[i-1][j])
            {
                int t1=Find(i*m+j),t2=Find((i-1)*m+j);
                //printf("%d %d\n",t1,t2);
                if(t1==t2)isok=1;
                else Union(t1,t2);
            }
            if(j>0 && s[i][j]==s[i][j-1])
            {
                int t1=Find(i*m+j),t2=Find(i*m+j-1);
                //printf("%d %d\n",t1,t2);
                if(t1==t2)isok=1;
                else Union(t1,t2);
            }
        }
    }
    if(isok)printf("Yes\n");
    else printf("No\n");
    return 0;
}