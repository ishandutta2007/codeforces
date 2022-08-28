#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int n,k,a[1000005],fl,nn;
int getmin(int x,int len)
{
	return (x+(x+len-1))*len/2;
}
int getmax(int x,int len)
{
	if(len>=30) return (int)1e12;
	return (x<<(len))-x;
}
signed main()
{
	scanf("%I64d%I64d",&n,&k);nn=n;
	int l=1,r=n;
	for(int i=1;i<=k;i++)
	{
		if(i==1&&(getmin(l,k-i+1)>n||getmax(r,k-i+1)<n))
		{
			//printf("%I64d,%I64d\n",getmin(l,n-i+1),getmax(r,n-i+1));
			printf("NO");
			return 0;
		}
		//if(i==1) printf("YES\n");
		if(getmax(l,k-i+1)>=n&&getmax(l,k-i+1)<=n)
		{
			a[i]=l;
			//printf("---");
			n-=l;
			r=l*2;
			l++;
			continue;
		}
		int ll=l,rr=r,mid;
		fl=0;
		while(ll<=rr)
		{
			int mid=(ll+rr)/2;
			if(getmin(mid,k-i+1)>n) rr=mid-1;
			else if(getmax(mid,k-i+1)<n) ll=mid+1;
			else
			{
				//printf("mid=%I64d,%I64d,%I64d\n",mid,getmin(mid,k-i+1),getmax(mid,k-i+1));
				a[i]=mid;
				n-=mid;
				r=2*mid;
				l=mid+1;
				fl=1;
				break;
			}
		}
		if(!fl)
		{
			//printf("%I64d,%I64d\n",getmin(l,n-i+1),getmax(r,n-i+1));
			printf("NO");
			return 0;
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++)
		sum+=a[i];
	if(sum!=nn)
	{
		//printf("sum=%I64d\n",sum);
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=k;i++)
		printf("%I64d ",a[i]);
	return 0;
}