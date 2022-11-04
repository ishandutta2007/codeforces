#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1000005],t[1000005];
int p[1000005],pp[1000005],r[1000005],rr[1000005];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    int m;
    scanf("%d",&m);
    int k,d;
    while(m--)
    {
        strcpy(t+1,s+1);
        scanf("%d%d",&k,&d);
        int loc=0;
        for(int i=1;i<=d;i++)
            for(int j=i;j<=k;j+=d)
                p[++loc]=j;
        for(int i=k+1;i<=n;i++)p[i]=i;
        rotate(p+1,p+2,p+n+1);
        for(int i=1;i<=n;i++)r[i]=i;
        int c=n+1-k;
        while(c>0)
        {
            if(c&1)
            {
                for(int i=1;i<=n;i++)rr[i]=r[p[i]];
                memcpy(r+1,rr+1,n*sizeof(int));
            }
            for(int i=1;i<=n;i++)pp[i]=p[p[i]];
            memcpy(p+1,pp+1,n*sizeof(int));
            c>>=1;
        }
        rotate(r+1,r+k,r+n+1);
        for(int i=1;i<=n;i++)s[i]=t[r[i]];
        printf("%s\n",s+1);
    }
    return 0;
}