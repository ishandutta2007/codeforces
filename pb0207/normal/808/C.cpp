#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[102],b[102],f[102];

int n,w;

int findNext()
{  
    int maxx=-1,t=0;
    for(int i=0;i<n;i++)
	{
        if(f[i]==0)
		{
            if(a[i]>maxx)
			{
                maxx=a[i];
                t=i;
            }
        }
    }
    f[t]=1;
    return t;
}
int main()
{

    scanf("%d %d",&n,&w);
    int minn=0;
    for(int i=0;i<n;i++)
	{
        scanf("%d",&a[i]);
        minn+=(a[i]+1)/2;
        b[i]=(a[i]+1)/2;
    }
    if(w<minn)
	{
        printf("-1");
    }
	else
	{
        int left=w-minn;
        while(left>0)
		{
            int t=findNext();
            if(left>a[t]/2)
			{
                left-=a[t]/2;
                b[t]=a[t];
            }
			else
			{
                b[t]+=left;
                left=0;
            }
        }
        for(int i=0;i<n-1;i++)
		{
            printf("%d ",b[i]);
        }
        printf("%d\n",b[n-1]);
    }
    return 0;
}