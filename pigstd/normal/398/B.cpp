#include<bits/stdc++.h>
using namespace std;

const int M=2e3+10;
double dp[M][M],H[M];
int n,m,n1,n2,r[M],c[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main()
{
	n1=n2=n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		if (r[a]==0)r[a]++,n1--;
		if (c[b]==0)c[b]++,n2--;
	}
	for (int i=1;i<=n;i++)H[i]=H[i-1]+1.0/i;
	for (int i=1;i<=n;i++)
		dp[0][i]=dp[i][0]=n*H[i];
	for (int i=1;i<=n1;i++)
		for (int j=1;j<=n2;j++)
			dp[i][j]=(n*n+i*j*dp[i-1][j-1]+i*(n-j)*dp[i-1][j]+(n-i)*j*dp[i][j-1])*1.0/((i+j)*n-i*j);
	printf("%.10lf",dp[n1][n2]);
	return 0;
}