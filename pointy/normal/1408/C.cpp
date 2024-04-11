#include<bits/stdc++.h>
using namespace std;
int n,l;
int a[100005]; 
double x[100005],y[100005];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> l;
		for (int i=1;i<=n;i++) cin >> a[i];
		a[n+1]=l,y[n+1]=0,x[0]=0;
		for (int i=1;i<=n+1;i++)
		{
			x[i]=x[i-1]+((double)(a[i]-a[i-1]))/((double)i);
		}
		for (int i=n;i>=0;i--)
		{
			y[i]=y[i+1]+((double)(a[i+1]-a[i]))/((double)(n-i+1));
		}
		for (int i=1;i<=n;i++)
		{
			if (x[i]==y[i]) 
			{
				printf("%.10lf\n",x[i]);
				goto uuu;
			}
		}
		for (int i=0;i<=n;i++)
		{
			if ((x[i+1]<=y[i]&&x[i+1]>=y[i+1])||(y[i]>=x[i]&&y[i]<=x[i+1]))
			{
				if (x[i]<y[i+1])
				{
					double v1=i+1,v2=n+1-i;
					double s=a[i+1]-a[i]-v1*(y[i+1]-x[i]);
					double t=s/(v1+v2)+y[i+1];
					printf("%.10lf\n",t);
					break;
				}
				else
				{
					double v1=i+1,v2=n+1-i;
					double s=a[i+1]-a[i]-v2*(x[i]-y[i+1]);
					double t=s/(v1+v2)+x[i];
					printf("%.10lf\n",t);
					break;
				}
			}
		}
		uuu:;
	}
	return 0;
}