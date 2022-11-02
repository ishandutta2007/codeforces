#include<cstdio>
#include<algorithm>
using namespace std;
const double eps=1e-14;
int n,x1,y1,x2,y2,tot,num,a,b,c,d;
double t[10],maxl,minr;
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	maxl=0;minr=1e20;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		tot=0;t[4]=0;
		if(x1<a&&a<x2&&y1<b&&b<y2)
		{
			t[++tot]=-eps;
			if(!c&&!d)t[++tot]=1e20;
		}
		if(c)
		{
			double tt=(double)(x1-a)/c;
			if(tt>-eps)
			{
				double y=b+tt*d;
				if(y1-eps<y&&y<y2+eps)t[++tot]=tt;
			}
			tt=(double)(x2-a)/c;
			if(tt>-eps)
			{
				double y=b+tt*d;
				if(y1-eps<y&&y<y2+eps)t[++tot]=tt;
			}
		}
		else
		{
			if((x1<a&&a<x2)&&d)
			{
				double tt=(double)(y1-b)/d;
				if(tt>-eps)
				{
					t[++tot]=tt;
					t[++tot]=(double)(y2-b)/d;
				}
			}
			if(a==x1||a==x2)
			{
				printf("-1");
				exit(0);
			}
		}
		if(d)
		{
			double tt=(double)(y1-b)/d;
			if(tt>-eps)
			{
				double x=a+tt*c;
				if(x1-eps<x&&x<x2+eps)t[++tot]=tt;
			}
			tt=(double)(y2-b)/d;
			if(tt>-eps)
			{
				double x=a+tt*c;
				if(x1-eps<x&&x<x2+eps)t[++tot]=tt;
			}
		}
		else
		{
			if((y1<b&&b<y2)&&c)
			{
				double tt=(double)(x1-a)/c;
				if(tt>-eps)
				{
					t[++tot]=tt;
					t[++tot]=(double)(x2-a)/c;
				}
			}
			if(b==y1||b==y2)
			{
				printf("-1");
				exit(0);
			}
		}
		sort(t+1,t+tot+1);
		if(tot==1)t[++tot]=t[1];
		maxl=max(maxl,t[1]+eps);
		minr=min(minr,t[tot]-eps);
	}
	if(maxl<minr+eps)printf("%.20lf",maxl);
	else printf("-1");
	return 0;
}