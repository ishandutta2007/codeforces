#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int id[100005];
int main()
{
    int n,m,c;
    scanf("%d%d%d",&n,&m,&c);
    if(m<n-1 || m>1LL*(n-1)*(n-2)/2+1)return 0*printf("-1");
    for(int i=1;i<=n;i++)id[i]=i;
    swap(id[1],id[c]);
    int u=1,v=2;
    while(m-->1)
    {
        printf("%d %d\n",id[u++],id[v++]);
        if(u>n-1)u=1,v++;
        if(v>n-1)v=1;
    }
    printf("%d %d\n",id[1],id[n]);
    return 0;
}