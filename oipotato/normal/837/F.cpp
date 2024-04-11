#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,pos;
long long k,a[200010];
long long add(long long a,long long b)
{
	if(k-b>a)
		return a+b;
	else
		return k;
}
long long mul(long long a,long long b)
{
	if(!a)
		return a*b;
	if(k/a>=b)
		return a*b;
	else
		return k;
}
struct Matrix
{
	long long a[6][6];
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix c;
		memset(c.a,0,sizeof(c.a));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					c.a[i][j]=add(c.a[i][j],mul(a.a[i][k],b.a[k][j]));
		return c;
	}
}ans,tmp;
void work1()
{
	int ans=0;
	for(;a[n]<k;ans++)
	{
		for(int i=2;i<=n;i++)
			a[i]=add(a[i],a[i-1]);
	}
	printf("%d\n",ans);
}
bool check(long long x)
{
	memset(ans.a,0,sizeof(ans.a));
	memset(tmp.a,0,sizeof(tmp.a));
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			tmp.a[i][j]=1;
	for(int i=1;i<=n;i++)
		ans.a[i][i]=1;
	for(;x;x>>=1)
	{
		if(x&1)ans=ans*tmp;
		tmp=tmp*tmp;
	}
	long long tans=0;
	for(int i=1;i<=n;i++)
		tans=add(tans,mul(a[i],ans.a[i][n]));
	return tans>=k;
}
void work2()
{
	long long l=0,r=k;
	for(;l<r-1;)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%I64d\n",r);
}
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i])
		{
			pos=i;
			break;
		}
	for(int i=1;i<=n;i++)
		if(a[i]>=k)
		{
			printf("0\n");
			return 0;
		}
	for(int i=1;i<=n-pos+1;i++)
		a[i]=a[i+pos-1];
	n-=pos-1;
	if(n>5)
		work1();
	else
		work2();
	return 0;
}