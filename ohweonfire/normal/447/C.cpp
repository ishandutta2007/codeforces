#include<cstdio>
using namespace std;
int n,a[100001];
int b[100001],tp=0;
int max=0;
int main()
{
	int i,j,k;
	scanf("%d",&n);
	b[++tp]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<=a[i-1]){b[++tp]=i;if(b[tp]-b[tp-1]+1>max)max=b[tp]-b[tp-1]+1;}
	}
	b[++tp]=n+1;if(b[tp]-b[tp-1]+1>max)max=b[tp]-b[tp-1]+1;
	if(tp==2){printf("%d\n",n);return 0;}
	for(i=1;i<=tp-3;i++)if(b[i+2]-b[i+1]==1&&a[b[i+2]]-a[b[i+1]-1]>1&&b[i+3]-b[i]>max)
	max=b[i+3]-b[i];
	for(i=1;i<=tp-2;i++)if((a[b[i+1]+1]-a[b[i+1]-1]>1||a[b[i+1]]-a[b[i+1]-2]>1)&&b[i+2]-b[i]>max)
	max=b[i+2]-b[i];
	//for(i=1;i<=tp;i++)printf("%d ",b[i]);printf("\n");
	printf("%d\n",max);
	return 0;
}