#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
struct person
{
    int v,id;
    bool operator < (const person &t)const
    {
        return v<t.v;
    }
}s[MAXN];
vector<int>res[2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i].v);
        s[i].id=i;
    }
    sort(s+1,s+n+1);
    int now=0;
    for(int i=2;i<=n;i+=2)
    {
        if(now<0)
        {
            res[0].push_back(s[i].id);
            res[1].push_back(s[i-1].id);
            now+=s[i].v-s[i-1].v;
        }
        else
        {
            res[0].push_back(s[i-1].id);
            res[1].push_back(s[i].id);
            now-=s[i].v-s[i-1].v;
        }
    }
    if(n&1)res[now>=0].push_back(s[n].id);
    for(int i=0;i<2;i++)
    {
        printf("%d\n",(int)res[i].size());
        for(int j=0;j<(int)res[i].size();j++)
            printf("%d ",res[i][j]);
        printf("\n");
    }
    return 0;
}