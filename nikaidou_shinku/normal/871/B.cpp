#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int query(int i,int j)
{
    printf("? %d %d\n",i,j);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    return res;
}
const int MAXN=5005;
int a[MAXN],b[MAXN],c[MAXN],p[MAXN],x[MAXN],r[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        a[i]=query(0,i);
    for(int i=0;i<n;i++)
        x[i]=query(i,0);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        bool flag=0;
        for(int j=0;j<n;j++)
        {
            b[j]=a[j]^i;
            if(b[j]>=n)flag=1;
        }
        if(flag)continue;
        for(int j=0;j<n;j++)
            c[j]=0;
        for(int j=0;j<n;j++)
            c[b[j]]++;
        for(int j=0;j<n;j++)
            if(c[j]!=1)flag=1;
        if(flag)continue;
        for(int j=0;j<n;j++)
            p[b[j]]=j;
        for(int j=0;j<n;j++)
            if((p[j]^b[0])!=x[j])flag=1;
        if(!flag)
        {
            cnt++;
            for(int j=0;j<n;j++)
                r[j]=p[j];
        }
    }
    printf("!\n");
    printf("%d\n",cnt);
    for(int i=0;i<n;i++)
        printf("%d%c",r[i]," \n"[i==n-1]);
    return 0;
}