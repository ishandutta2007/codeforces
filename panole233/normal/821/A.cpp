#include<cstdio>
#include<cstring>

int n,a[51][51];
bool bo;

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (a[i][j]!=1)
			{
				bo=0;
				for (int k=1; k<=n; k++)
					if (k!=i)
					{
						for (int l=1; l<=n; l++)
							if (l!=j)
								if (a[k][j]+a[i][l]==a[i][j]) {bo=1; break;}
						if (bo) break;
					}
				if (!bo) {printf("No"); return 0;}
			}
	printf("Yes");
	return 0;
}