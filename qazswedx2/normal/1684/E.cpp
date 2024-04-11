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
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int nw=m,las=-1;
		bt=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r<n&&a[r+1]==a[l]) r++;
			nw-=(a[l]-las-1);
			las=a[l];
			if(nw<0)
			{
				b[++bt]=r-l+1;
			}
		}
		sort(b+1,b+bt+1);
		int ans=0;
		for(int i=1;i<=bt;i++)
		{
			m-=b[i];
			if(m<0)
			{
				ans=bt-i+1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}