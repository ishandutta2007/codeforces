#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
int pre[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%*d"),pre[i]=INF;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        pre[b]=min(pre[b],c);
    }
    int cnt=0;
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]<INF)res+=pre[i];
        else cnt++;
    }
    return 0*printf("%lld",cnt>1 ? -1 : res);
}