#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int a[5300][5300],sum[5300][5300],n;
char s[5300];
bool check(int x1,int y1,int x2,int y2)
{
	int tmp=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
	return tmp==0||tmp==(x2-x1+1)*(y2-y1+1);
}
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%s",s+1);
		rep(j,n/4)
		{
			int x='0'<=s[j]&&s[j]<='9'?s[j]-'0':s[j]-'A'+10;
			for(int p=0;p<4;p++)a[i][j*4-p]=(x>>p)&1;
		}
	}
	rep(i,n)rep(j,n)sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	for(int i=n;i>1;i--)
	if(n%i==0)
	{
		bool flag=1;
		for(int j=1;j<=n&&flag;j+=i)for(int k=1;k<=n&&flag;k+=i)flag&=check(j,k,j+i-1,k+i-1);
		if(flag){printf("%d\n",i);return 0;}
	}
	puts("1");
	return 0;
}