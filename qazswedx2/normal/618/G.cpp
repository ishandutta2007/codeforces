#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
//#define double long double
double p,a[105][105],b[105][105],dp[105][105],sum[105][105];
int n,pn=70; 
struct mat
{
	int x,y;
	double val[105][105];
	mat(int x=0,int y=0):x(x),y(y){memset(val,0,sizeof(val));}
}f,s;
mat operator*(const mat& a,const mat& b)
{
	mat c(a.x,b.y);
	for(int i=1;i<=c.x;i++)
		for(int j=1;j<=c.y;j++)
			for(int k=1;k<=a.y;k++)
				c.val[i][j]+=a.val[i][k]*b.val[k][j];
	return c;
}
mat matpow(mat x,int y)
{
	mat ans=x;
	y--;
	while(y)
	{
		if(y&1) ans=ans*x;
		x=x*x;
		y/=2;
	}
	return ans;
}
int main()
{
	scanf("%d%lf",&n,&p);
	p*=1e-9;
	for(int i=1;i<=pn+5;i++)
	{
		a[i][1]=p,a[i][2]=1-p+p*p;
		b[i][1]=0,b[i][2]=1;
	}
	a[1][2]=1-p;
	b[1][2]=1;
	for(int i=2;i<=pn+5;i++)
		for(int j=3;j<=pn;j++)
		{
			a[i][j]=a[i-1][j-1]*a[i][j-1];
			b[i][j]=a[i-1][j-1]*b[i][j-1];
			//if(i<=10&&j<=10)
			//if(i-)printf("i=%d,j=%d,a=%f,b=%f\n",i,j,a[i][j],b[i][j]);
		}
	dp[1][1]=1,dp[1][2]=2;
	for(int i=2;i<=min(pn+5,n);i++)
		for(int j=1;j<=pn;j++)
		{
			if(j==1)
			{
				for(int k=2;k<=pn;k++)
				{
					sum[i][j]+=b[i-1][k]*(1-a[i-2][k]);
					dp[i][j]+=dp[i-1][k]*b[i-1][k]*(1-a[i-2][k]);
				}
			}
			else
			{
				for(int k=1;k<j;k++)
				{
					sum[i][j]+=a[i-1][k]*(1-a[i-2][k]);
					dp[i][j]+=dp[i-1][k]*a[i-1][k]*(1-a[i-2][k]);
				}
			//	if(fabs(sum[i][j]-(1-a[i-1][j]))>1e-15)printf("sum=%f,%f\n",sum[i][j],(1-a[i-1][j]));
			}
			dp[i][j]/=sum[i][j];
			dp[i][j]+=j;
		}
	if(n<=pn+5)
	{
		double ans=0;
		for(int i=1;i<=pn;i++)
			ans+=dp[n][i]*a[n][i]*(1-a[n-1][i]);
		printf("%f",ans);
		return 0;
	}
	f=mat(pn+1,pn+1);
	s=mat(pn+1,1);
	for(int i=1;i<=pn;i++)
	{
		if(i==1)
		{
			for(int j=2;j<=pn;j++)
				f.val[i][j]=b[pn][j]*(1-a[pn-1][j]);
		}
		else
		{
			for(int j=1;j<i;j++)
			{
				f.val[i][j]=a[pn][j]*(1-a[pn-1][j])/sum[pn][i];
			//	if(fabs(sum[pn][i]-(1-a[pn][i]))>1e-15) printf("i=%d\n",i);
			}
		}
	}
	for(int i=1;i<=pn;i++)
		f.val[i][pn+1]=i;
	f.val[pn+1][pn+1]=1;
	for(int i=1;i<=pn;i++)
		s.val[i][1]=dp[pn+5][i];
	s.val[pn+1][1]=1;
	s=matpow(f,n-pn-5)*s;
	double ans=0;
	for(int i=1;i<=pn;i++)
	{
		ans+=s.val[i][1]*a[pn][i]*(1-a[pn-1][i]);
		//printf("%f ",s.val[i][1]*a[pn][i]*(1-a[pn-1][i]));
	}
	printf("%f",ans);
	return 0;
}