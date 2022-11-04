#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN],fa[MAXN];
vector<int>id[MAXN];
int main()
{
    int n,t,k;
    scanf("%d%d%d",&n,&t,&k);
    id[0].push_back(1);
    for(int i=(a[0]=1),j=1;i<=t;i++)
    {
        scanf("%d",&a[i]);
        for(int k=0;k<a[i];k++)
            id[i].push_back(++j);
    }
    int r=a[t];
    for(int i=1;i<=t;i++)
        r+=max(0,a[i-1]-a[i]);
    if(r>k)return 0*printf("-1");
    for(int i=1;i<=t;i++)
        fa[i]=min(a[i],a[i-1]);
    for(int i=1;i<=t;i++)
        while(r<k && fa[i]>1)fa[i]--,r++;
    if(r<k)return 0*printf("-1");
    printf("%d\n",n);
    for(int i=1;i<=t;i++)
        for(int j=0;j<(int)id[i].size();j++)
            printf("%d %d\n",id[i-1][j%fa[i]],id[i][j]);
    return 0;
}