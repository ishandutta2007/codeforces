#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,a[1000005],b[1000005],bt;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+m+1);
		bt=0;
		for(int i=1;i<m;i++)
			b[++bt]=a[i+1]-a[i]-1;
		b[++bt]=(a[1]+n)-a[m]-1;
		sort(b+1,b+bt+1);
		int ans=0;
		int q=0;
		for(int i=bt;i>0;i--)
		{
			int u=b[i]-q;
			//printf("i=%d,b=%d,u=%d,ans=%d\n",i,b[i],u,ans);
			if(u>2) ans+=u-1,q+=4;
			if(u>=1&&u<=2) ans++,q+=2;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}