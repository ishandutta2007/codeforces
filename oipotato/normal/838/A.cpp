#include <cstdio>
#include <algorithm>
using namespace std;
int c[5010][5010],a[2510][2510],N,M,ans,tot,prime[2510];
bool notp[2510];
inline int lowbit(int x){return x&(-x);}
void modify(int x,int y)
{
	for(int i=x;i<=5000;i+=lowbit(i))
		for(int j=y;j<=5000;j+=lowbit(j))
			c[i][j]++;
}
int sum(int x,int y)
{
	int s=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			s+=c[i][j];
	return s;
}
void work(int k)
{
	int n=((N-1)/k+1)*k;
	int m=((M-1)/k+1)*k;
	int tans=0,p;
	for(int i=1;i<=n;i+=k)
		for(int j=1;j<=m;j+=k)
		{
			p=sum(i+k-1,j+k-1)+sum(i-1,j-1)-sum(i-1,j+k-1)-sum(i+k-1,j-1);
			tans+=min(p,k*k-p);
		}
	ans=min(ans,tans);
}
int main()
{
	scanf("%d%d\n",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			a[i][j]=getchar()-'0';
			if(a[i][j])
				modify(i,j);
		}
		getchar();
	}
	ans=5000*5000;
	for(int i=2;i<=2500;i++)
	{
		if(!notp[i])
		{
			prime[++tot]=i;
			work(i);
		}
		for(int j=1;j<=tot;j++)
		{
			if(i*prime[j]>2500)
				break;
			notp[i*prime[j]]=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}