#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int lim=1;
	while(lim<n) lim<<=1;
	for(int k=1;k<lim;k<<=1)
		for(int i=0;i<lim;i+=2*k)
			for(int j=0;j<k;j++)
				a[i+j+k]^=a[i+j];
	for(int i=n;i<lim;i++)
		a[i]=0;
	for(int k=1;k<lim;k<<=1)
		for(int i=0;i<lim;i+=2*k)
			for(int j=0;j<k;j++)
				a[i+j]^=a[i+j+k];
	for(int i=n-1;i>=0;i--)
		printf("%d ",a[i]);
	return 0;
}