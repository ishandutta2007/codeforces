#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
int a[MAXN],b[MAXN],p[MAXN],c[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            c[j]=0;
        for(int j=1;j<=n;j++)
            if(j!=i)c[a[j]]++,p[j]=a[j];
        int ok=1,t=0;
        for(int j=1;j<=n;j++)
        {
            if(c[j]>=2)ok=0;
            if(c[j]==0)t=j;
        }
        if(ok)
        {
            p[i]=t;
            int dif=0;
            for(int i=1;i<=n;i++)
                dif+=(p[i]==b[i]);
            if(dif==n-1)
            {
                for(int i=1;i<=n;i++)
                    printf("%d ",p[i]);
                return 0;
            }
        }
    }
    return 0;
}