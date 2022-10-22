#include<bits/stdc++.h>
using namespace std;

const int N=401;

int T;

int n,m,a[N][N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		int ans=1;
		ans&=a[1][1]<=2;
		ans&=a[1][m]<=2;
		ans&=a[n][1]<=2;
		ans&=a[n][m]<=2;
		for(int i=2;i<n;i++)
			ans&=a[i][1]<=3,ans&=a[i][m]<=3;
		for(int i=2;i<m;i++)
			ans&=a[1][i]<=3,ans&=a[n][i]<=3; 
		for(int i=2;i<n;i++)
			for(int j=2;j<m;j++)
				ans&=a[i][j]<=4;
		a[1][1]=2;
		a[1][m]=2;
		a[n][1]=2;
		a[n][m]=2;
		for(int i=2;i<n;i++)
			a[i][1]=3,a[i][m]=3;
		for(int i=2;i<m;i++)
			a[1][i]=3,a[n][i]=3; 
		for(int i=2;i<n;i++)
			for(int j=2;j<m;j++)
				a[i][j]=4;
		if(ans)
		{
			puts("YES");
			for(int i=1;i<=n;i++,puts(""))
				for(int j=1;j<=m;j++,putchar(' '))
					printf("%d",a[i][j]);
		}
		else
		{
			puts("NO");
		}
	}
}