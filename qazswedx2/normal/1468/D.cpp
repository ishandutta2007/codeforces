#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,a,b,c[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(int i=1;i<=m;i++)
			scanf("%d",&c[i]);
		sort(c+1,c+m+1);
		int nw=a-b,k;
		if(nw<0) nw=-nw;
		nw--;
		if(a<b) k=b-2;
		else k=n-b-1;
		int q=m;
	//	printf("nw=%d,k=%d\n",nw,k);
		int ans=0;
		while(nw--)
		{
			while(q&&c[q]>k) q--;
			if(!q) break;
		//	printf("q=%d\n",q);
			ans++;
			k--;
			q--;
		}
		printf("%d\n",ans);
	}
	return 0;
}