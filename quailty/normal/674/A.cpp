#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
int t[MAXN],c[MAXN],res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    reverse(t+1,t+n+1);
    for(int i=1;i<=n;i++)
    {
        memset(c,0,sizeof(c));
        int now=0,mx=0;
        for(int j=i;j<=n;j++)
        {
            ++c[t[j]];
            if(mx<c[t[j]])
            {
                now=t[j];
                mx=c[t[j]];
            }
            else if(mx==c[t[j]])
                now=min(now,t[j]);
            res[now]++;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}