#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int m;
int check(int *a,int &ans0,int &ans1)
{
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	int fl=0,l=-1,r=-1;
	for(int i=2;i<=m;i++)
		if(a[i]<a[i-1])
		{
			fl=1;
			l=i-1;
			while(l>1&&a[l-1]==a[l]) l--;
			break;
		}
	if(!fl) return 0;
	for(int i=m;i>1;i--)
		if(a[i]<a[i-1])
		{
			r=i;
			while(r<m&&a[r+1]==a[r]) r++;
			break;
		}
	ans0=l,ans1=r;
/*	for(int i=m;i>1;i--)
		if(a[i]<a[i-1])
		{
			int u=upper_bound(a+1,a+i,a[i])-a;
		//	if(u!=i) swap(a[u],a[i]);
			ans0=u,ans1=i;
			fl=1;
			break;
		}*/
//	printf("ans0=%d,ans1=%d\n",ans0,ans1);
//	for(int i=1;i<=m;i++)
//		if(a[i]<a[i-1])
//			return -1;
	return fl;
}
int T,n,a[1000005];
inline int F(int x,int y)
{
	return (x-1)*m+y;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		int fl=0,ans0=1,ans1=1;
		for(int i=1;i<=n;i++)
		{
			int v0=0,v1=0;
			int q=check(a+(i-1)*m,v0,v1);
			if(q==-1)
			{
				fl=1;
			//	break;
			}
			if(q)
			{
				if(ans0==ans1) ans0=v0,ans1=v1;
				else if(ans0!=v0||ans1!=v1)
				{
					fl=1;
				//	break;
				}
			}
		}
		for(int i=1;i<=n;i++)
			swap(a[F(i,ans0)],a[F(i,ans1)]);
		for(int i=1;i<=n;i++)
			for(int j=2;j<=m;j++)
				if(a[F(i,j)]<a[F(i,j-1)])
					fl=1;
		if(fl) printf("-1\n");
		else printf("%d %d\n",ans0,ans1);
	}
}