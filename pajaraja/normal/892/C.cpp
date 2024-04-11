#include <bits/stdc++.h>
using namespace std;
int a[2007],f[2007];
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) if(a[i]==1) cnt++;
	if(cnt>0)
	{
		printf("%d",n-cnt);
		return 0;
	}
	int min=100000000,cur=gcd(a[0],a[1]);
	for(int i=2;i<n;i++) cur=gcd(cur,a[i]);
	if(cur>1)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cur=a[i];
		int k=i;
		while(k<n && cur>1)
		{
			cur=gcd(cur,a[k]);
			k++;
		}
		if(cur==1) min=fmin(min,k-i-1);
	}
	printf("%d",n+min-1);
}