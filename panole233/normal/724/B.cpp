#include <cstdio>
#include <cstring>

int n,m,a[21][21];
bool b[21];

void swap(int &a,int &b)
{
	int t=a; a=b; b=t;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
	{
		memset(b,0,sizeof(b));
		for (int j=1; j<=m; j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j]<=m) b[a[i][j]]=1;	
		}
		for (int j=1; j<=m; j++) if (!b[j]) {printf("NO\n"); return 0;}
	}
	bool bo=1;
	for (int i=1; i<=n; i++)
	{
		int tot=0;
		for (int j=1; j<=m; j++)
			if (a[i][j]!=j) tot++;
		if (tot>2) {bo=0; break;}
	}
	if (bo) {printf("YES\n"); return 0;}
	for (int i=1; i<m; i++)
		for (int j=i+1; j<=m; j++)
		{
			for (int k=1; k<=n; k++) swap(a[k][i],a[k][j]);
			bo=1;
			for (int i=1; i<=n; i++)
			{
				int tot=0;
				for (int j=1; j<=m; j++)
					if (a[i][j]!=j) tot++;
				if (tot>2) {bo=0; break;}
			}
			if (bo) {printf("YES\n"); return 0;}
			for (int k=1; k<=n; k++) swap(a[k][i],a[k][j]);
		}
	printf("NO\n");
}