#include<cstdio>
#include<cstring>

unsigned int a[2001][64],t;
int n,d[2001],T,m,x,y;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<64; j++) a[i][j]=0;
			d[i]=0;
		}
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d",&x,&y);
			a[x][y>>5]^=(1ll<<(y&31));
			a[y][x>>5]^=(1ll<<(x&31));
			d[x]++; d[y]++;
		}
		bool bo=1;
		for (int i=1; i<=n; i++)
			if (d[i]&1) {bo=0; break;}
		if (bo) {puts("1"); for (int i=1; i<=n; i++) printf("1 "); puts(""); continue;}
		for (int i=1; i<=n; i++) 
			if (d[i]&1) a[i][i>>5]^=(1ll<<(i&31)),a[i][0]^=1;
		for (int i=1; i<=n; i++)
		{
			if (!((a[i][i>>5]>>(i&31))&1))
			{
				for (int j=i+1; j<=n; j++)
					if ((a[j][i>>5]>>(i&31))&1)
					{
						for (int k=0; k<64; k++) t=a[i][k],a[i][k]=a[j][k],a[j][k]=t;
						break;
					}
			}
			for (int j=1; j<=n; j++)
				if (i!=j&&((a[j][i>>5]>>(i&31))&1))
					for (int k=0; k<64; k++) a[j][k]^=a[i][k];
		}
		puts("2");
		for (int i=1; i<=n; i++) printf("%d ",(a[i][0]&1)+1);
		puts("");
	}
	return 0;
}