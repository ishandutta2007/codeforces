#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=2505;
const long double pi=acos(-1.0L);

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

long double a[N];
int C[N][4],x[N],y[N];

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for (int i=C[0][0]=1;i<=n;i++)
	for (int j=C[i][0]=1;j<=3;j++)
	C[i][j]=C[i-1][j-1]+C[i-1][j];
	for (int k=1;k<=n;k++)
	{
		int m=0;
		for (int i=1;i<=n;i++) if (i!=k) a[++m]=atan2((long double)(y[i]-y[k]),(long double)(x[i]-x[k]));
		sort(a+1,a+1+m);
		for (int i=1,j=1,k=1;i<=m;i++)
		{
			while (j<=i&&a[i]-a[j]>pi) j++;
			while (k<=m&&a[k]-a[i]<pi) k++;
			ans+=C[i-1][3]-C[j-1+k-i-1][3];
		}
	}
	print(ans);
	
	return 0;
}