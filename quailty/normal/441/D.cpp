#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3005;
int p[MAXN],id[MAXN];
vector<int>cir[MAXN];
vector<pair<int,int> >res;
int cal(int n)
{
    for(int i=1;i<=n;i++)
        id[i]=0,cir[i].clear();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(id[i])continue;
        cnt++;
        int t=i;
        do
        {
            id[t]=i;
            cir[i].push_back(t);
            t=p[t];
        }while(t!=i);
    }
    return cnt;
}
void solveLess(int n)
{
    for(int i=1;i<=n;i++)
    {
        if((int)cir[id[i]].size()==1)continue;
        int mi=n;
        for(int j=0;j<(int)cir[id[i]].size();j++)
            if(cir[id[i]][j]>i)mi=min(mi,cir[id[i]][j]);
        res.push_back(make_pair(i,mi));
        swap(p[i],p[mi]);
        break;
    }
}
void solveMore(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(id[i]==id[1])continue;
        res.push_back(make_pair(1,i));
        swap(p[1],p[i]);
        break;
    }
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    scanf("%d",&m);
    while(1)
    {
        int t=cal(n);
        if(t==n-m)break;
        if(t<n-m)solveLess(n);
        else solveMore(n);
    }
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d %d ",res[i].first,res[i].second);
    return 0;
}