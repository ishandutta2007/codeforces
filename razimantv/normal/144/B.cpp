# include <cstdio>
# include <algorithm>

using namespace std;

int x[1000],y[1000],r[1000];

int main()
{
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	
	if(x1>x2)swap(x1,x2);
	if(y1>y2)swap(y1,y2);
	
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d",x+i,y+i,r+i);
		r[i]*=r[i];
	}
	
	int ret=0;
	for(int coord=x1;coord<x2;coord++)
	{
		for(int i=0;i<N;i++)
			if((x[i]-coord)*(x[i]-coord)+(y[i]-y1)*(y[i]-y1)<=r[i])
			{
				ret++;
				break;
			}
	}
	for(int coord=y1;coord<y2;coord++)
	{
		for(int i=0;i<N;i++)
			if((x[i]-x2)*(x[i]-x2)+(y[i]-coord)*(y[i]-coord)<=r[i])
			{
				ret++;
				break;
			}
	}
	for(int coord=x2;coord>x1;coord--)
	{
		for(int i=0;i<N;i++)
			if((x[i]-coord)*(x[i]-coord)+(y[i]-y2)*(y[i]-y2)<=r[i])
			{
				ret++;
				break;
			}
	}
	for(int coord=y2;coord>y1;coord--)
	{
		for(int i=0;i<N;i++)
			if((x[i]-x1)*(x[i]-x1)+(y[i]-coord)*(y[i]-coord)<=r[i])
			{
				ret++;
				break;
			}
	}
	ret=2*(y2-y1)+2*(x2-x1)-ret;
	printf("%d\n",ret);
}