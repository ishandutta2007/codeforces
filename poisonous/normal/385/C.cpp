#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int a[10000010],b[1000100],g[10000100],p[10000100],i[10000100];
int main()
{
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(i,0,sizeof(i));
    int c,d,e,f,t=0;
    cin>>c;
    for(d=1;d<=c;d++)
    {
        scanf("%d",&b[d]);
        if(b[d]>t)
            t=b[d];
    }
    int m=0;
      for(d=2;d<=t;d++)
        if(p[d]==0)
        {
            m++;
           i[m]=d;
            for(e=2;d*e<=t;e++)
                p[d*e]=1;
        }
        for(d=1;d<=c;d++)
    {
        int n=(int)(sqrt(b[d]));
        for(e=1;i[e]<=n;e++)
        {
            if(i[e]>b[d])
                break;
            if(b[d]%i[e]==0)
                a[i[e]]++;
            while(b[d]%i[e]==0)
                b[d]/=i[e];
        }
        if(b[d]!=1)
            a[b[d]]++;
    }
    g[0]=0;
    for(d=1;d<=10000000;d++)
        g[d]=g[d-1]+a[d];
    cin>>c;
    for(d=1;d<=c;d++)
    {
        scanf("%d%d",&e,&f);
        if(f>10000000)
        f=10000000;
        if(e>10000000)
        e=10000000;
        printf("%d\n",g[f]-g[e-1]);
    }
}