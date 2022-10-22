#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

struct data{
    int x1,y1,x2,y2;
}sf[100005];

int d,n,m,cl,cr,ct,cb,xl[N],yl[N],xr[N],yr[N];

int main()
{
    scanf("%d%d%d",&d,&n,&m);
    for(int i=1;i<=d;i++)
    {    
        scanf("%d%d%d%d",&sf[i].x1,&sf[i].y1,&sf[i].x2,&sf[i].y2);
        xl[min(sf[i].x1,sf[i].x2)]++;
        yl[min(sf[i].y1,sf[i].y2)]++;
        xr[max(sf[i].x1,sf[i].x2)]++;
        yr[max(sf[i].y1,sf[i].y2)]++;
    }
    scanf("%d%d%d%d",&cl,&cr,&ct,&cb);
    for(int i=1;i<=n;i++)
		xl[i]+=xl[i-1];
    for(int i=1;i<=m;i++)
		yl[i]+=yl[i-1];
    for(int i=n;i;i--)
		xr[i]+=xr[i+1];
    for(int i=m;i;i--)
		yr[i]+=yr[i+1]; 
    for(int i=1;i<=d;i++)
    {
        int l=xl[max(sf[i].x1,sf[i].x2)-1];
        int r=xr[min(sf[i].x1,sf[i].x2)+1];
        if(sf[i].x1!=sf[i].x2)
			l--,r--;
        int t=yl[max(sf[i].y1,sf[i].y2)-1];
        int b=yr[min(sf[i].y1,sf[i].y2)+1];
        if(sf[i].y1!=sf[i].y2)
			t--,b--;
        if(l==cl&&r==cr&&t==ct&&b==cb)
        {
			printf("%d\n",i);
			exit(0);
		}
    }
    printf("-1\n");
    return 0;
}