#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int nxt[1000005],pre[1000005],res[200005];
int main()
{
    int n;
    scanf("%d",&n);
    memset(nxt,-1,sizeof(nxt));
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        nxt[a]=b;
        pre[b]=a;
    }
    for(int i=0,j=0;i==0 || j;i+=2,j=nxt[j])
        res[i]=j;
    int loc=0;
    if(n&1)
    {
        for(int i=1;i<=1000000;i++)
            if(nxt[i]>=0 && pre[i]==-1)loc=i;
        for(int i=1,j=loc;~j;i+=2,j=nxt[j])
            res[i]=j;
    }
    else
    {
        int loc=pre[0];
        for(int i=n-1,j=loc;j;i-=2,j=pre[j])
            res[i]=j;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}
/*
5
0 2
1 3
2 4
3 5
4 0
*/