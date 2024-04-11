#include<bits/stdc++.h>
using namespace std;

int f[51][51][51][51],n,a[51][51];
char str[101];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",str);
		for (int j=0; j<n; j++) a[i][j+1]=(str[j]=='#');
	}
	for (int I=1; I<=n; I++)
		for (int J=1; J<=n; J++)
			for (int k=I; k<=n; k++)
				for (int l=J; l<=n; l++)
				{
					int i=k-I+1,j=l-J+1;
					if (i==k&&j==l) {f[i][j][k][l]=a[i][j]; continue;}
					f[i][j][k][l]=max(k-i+1,l-j+1);
					for (int m=i; m<k; m++) f[i][j][k][l]=min(f[i][j][k][l],f[i][j][m][l]+f[m+1][j][k][l]);
					for (int m=j; m<l; m++) f[i][j][k][l]=min(f[i][j][k][l],f[i][j][k][m]+f[i][m+1][k][l]);
				}
	printf("%d\n",f[1][1][n][n]);
	return 0;
}