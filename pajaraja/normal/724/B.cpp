#include <iostream>
#include <stdio.h>
int main(int argc, char** argv) 
{
	int n,m;
	bool da=false;
	scanf("%d%d",&n,&m);
	int a[n][m];
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				int d=a[k][i];
				a[k][i]=a[k][j];
				a[k][j]=d;
			}
			bool z=true;
			for(int k=0;k<n;k++)
			{
				int br=0;
				for(int t=1;t<=m;t++) if(t!=a[k][t-1]) br++;
				if(br>2) z=false;
			}
			for(int k=0;k<n;k++)
			{
				int d=a[k][i];
				a[k][i]=a[k][j];
				a[k][j]=d;
			}
			if(z) da=true;
		}
	}
	if(da) printf("YES");
	else printf("NO");
	return 0;
}