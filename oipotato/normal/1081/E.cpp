#include<cstdio>
using namespace std;
int a[100010],b[100010],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++)scanf("%d",&a[2*i]);
	b[n/2]=-1;
	for(int i=1;i*i<a[n];i++)if(a[n]%i==0&&(a[n]/i-i)%2==0){b[n/2]=(a[n]/i-i)/2;break;}
	if(b[n/2]==-1){puts("No");return 0;}
	for(int i=n/2-1;i;i--)
	{
		int x=a[2*i];
		b[i]=-1;
		for(int j=1;j*j<x;j++)
		if(x%j==0&&(x/j-j)%2==0&&(x/j+j)/2<b[i+1])
		{
			b[i]=(x/j-j)/2;
			break;
		}
		if(b[i]==-1){puts("No");return 0;}
	}
	puts("Yes");
	long long sum=0;
	for(int i=1;i<=n/2;i++)
	{
		long long x=1ll*b[i]*b[i]-sum;
		printf("%lld %d",x,a[2*i]);
		sum+=x+a[2*i];
		if(i==n/2)puts("");else putchar(' ');
	}
	return 0;
}