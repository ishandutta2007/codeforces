#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
void update(int &x,int y,int n)
{
    x+=y;
    while(x>=n)x-=n;
    while(x<0)x+=n;
}
int res[1000005];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int p[2]={0,1};
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int x;
            scanf("%d",&x);
            update(p[0],x,n);
            update(p[1],x,n);
        }
        else
        {
            for(int i=0;i<2;i++)
            {
                if(p[i]&1)update(p[i],-1,n);
                else update(p[i],1,n);
            }
        }
    }
    for(int i=p[0],j=0;j<n/2;j++,update(i,2,n))
        res[i]=2*j+1;
    for(int i=p[1],j=0;j<n/2;j++,update(i,2,n))
        res[i]=2*j+2;
    for(int i=0;i<n;i++)
        printf("%d ",res[i]);
    return 0;
}