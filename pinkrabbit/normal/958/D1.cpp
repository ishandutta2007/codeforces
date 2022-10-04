#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int gcd(int a,int b)
{
	if(a>b) return gcd(b,a);
	if(a==0) return b;
	return gcd(b%a,a);
}
int n,a[3][200005],num[205][205];
int main()
{
	n=read();
	for(int i=1,s;i<=n;i++)
	{
		a[0][i]=read(),a[1][i]=read(),a[2][i]=read();
		s=gcd(a[0][i]+a[1][i],a[2][i]);
		num[(a[0][i]+a[1][i])/s][a[2][i]/s]++;
	}
	for(int i=1;i<=n;i++)
	{
		int s=gcd(a[0][i]+a[1][i],a[2][i]);
		printf("%d ",num[(a[0][i]+a[1][i])/s][a[2][i]/s]);
	}
	return 0;
}