#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int x[55],y[55],d[55],a[55];
vector<pair<int,int> >v;
void work(int n)
{
    for(int i=1;i<n;i++)
        d[i]=x[i]-x[i-1];
    for(int i=2;i<n;i++)
        a[i]=(d[i]-d[i-1])/2;
    a[1]=d[1];
    for(int i=2;i<n;i++)
        a[1]+=a[i];
    int det=x[0];
    for(int i=1;i<=n;i++)
        det-=a[i]*(i-1);
    v.clear();
    for(int i=1;i<n;i++)
        if(a[i])v.push_back(make_pair(a[i],i));
    while(det<0)
    {
        v.push_back(make_pair(-50,0));
        det+=50;
    }
    while(det>0)
    {
        v.push_back(make_pair(min(det,50),0));
        det-=min(det,50);
    }
    if((int)v.size()==0)printf("0");
    else if((int)v.size()==1)
    {
        if(v[0].first<0)printf("(0-");
        if(!v[0].second)
            printf("%d",abs(v[0].first));
        else
            printf("(%d*abs((t-%d)))",abs(v[0].first),v[0].second);
        if(v[0].first<0)printf(")");
    }
    else
    {
        for(int i=1;i<(int)v.size();i++)
            printf("(");
        for(int i=0;i<(int)v.size();i++)
        {
            if(i==0)
            {
                if(v[i].first<0)printf("((0-%d)*abs((t-%d)))",abs(v[i].first),v[i].second);
                else printf("(%d*abs((t-%d)))",abs(v[i].first),v[i].second);
            }
            else
            {
                printf("%s",(v[i].first<0 ? "-" : "+"));
                if(!v[i].second)
                    printf("%d",abs(v[i].first));
                else
                    printf("(%d*abs((t-%d)))",abs(v[i].first),v[i].second);
                printf(")");
            }
        }
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%*d",&x[i],&y[i]);
    if(n==1)
    {
        printf("%d\n%d\n",x[0],y[0]);
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(x[i]&1)x[i]--;
            if(y[i]&1)y[i]--;
        }
        work(n);
        memcpy(x,y,sizeof(y));
        work(n);
    }
    return 0;
}