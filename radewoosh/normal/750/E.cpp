#include <bits/stdc++.h>
using namespace std;

int n, q;

char wcz[1000007];
int tab[1000007];

int n1;

int inf=1000000;

int drzewo[530000][5][5];

int sta[5];
int now[5];

int potenga(int v)
{
	for (int i=1; 1; i<<=1)
		if (i>=v)
			return i;
}

void start(int v, int a, int b)
{
	for (int i=0; i<=4; i++)
		for (int j=0; j<=4; j++)
			drzewo[v][i][j]=inf;
	if (a==b)
	{
		if (!tab[a])
		{
			for (int i=0; i<=4; i++)
				drzewo[v][i][i]=0;
		}
		if (tab[a]==1)
		{
			for (int i=0; i<=4; i++)
				drzewo[v][i][i]=0;
			drzewo[v][0][0]=1;
			drzewo[v][0][1]=0;
		}
		if (tab[a]==2)
		{
			for (int i=0; i<=4; i++)
				drzewo[v][i][i]=0;
			drzewo[v][1][1]=1;
			drzewo[v][1][2]=0;
		}
		if (tab[a]==3)
		{
			for (int i=0; i<=4; i++)
				drzewo[v][i][i]=0;
			drzewo[v][2][2]=1;
			drzewo[v][2][3]=0;
		}
		if (tab[a]==4)
		{
			for (int i=0; i<=4; i++)
				drzewo[v][i][i]=0;
			drzewo[v][3][3]=1;
			drzewo[v][3][4]=0;
		}
		if (tab[a]==-1)
		{
			for (int i=0; i<=4; i++)
				drzewo[v][i][i]=0;
			drzewo[v][3][3]=1;
			drzewo[v][4][4]=1;
		}
		return;
	}
	start((v<<1), a, (a+b)>>1);
	start((v<<1)^1, (a+b+2)>>1, b);
	for (int i=0; i<=4; i++)
		for (int j=i; j<=4; j++)
			for (int l=j; l<=4; l++)
				drzewo[v][i][l]=min(drzewo[v][i][l], drzewo[(v<<1)][i][j]+drzewo[(v<<1)^1][j][l]);
}

void czyt(int v, int a, int b, int graa, int grab)
{
	//printf("jade %d %d %d\n", v, a, b);
	if (a>=graa && b<=grab)
	{
		/*printf("w %d %d\n", a, b);
		for (int i=0; i<=4; i++)
			for (int j=i; j<=4; j++)
				printf("z %d do %d    %d\n", i, j, drzewo[v][i][j]);
		printf("\n");*/
		for (int i=0; i<=4; i++)
		{
			now[i]=sta[i];
			sta[i]=inf;
		}
		for (int i=0; i<=4; i++)
			for (int j=i; j<=4; j++)
				sta[j]=min(sta[j], now[i]+drzewo[v][i][j]);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	czyt((v<<1), a, (a+b)>>1, graa, grab);
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
}

int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", wcz+1);
	n1=potenga(n);
	for (int i=1; i<=n; i++)
	{
		if (wcz[i]=='2')
			tab[i]=1;
		if (wcz[i]=='0')
			tab[i]=2;
		if (wcz[i]=='1')
			tab[i]=3;
		if (wcz[i]=='6')
			tab[i]=-1;
		if (wcz[i]=='7')
			tab[i]=4;
	}
	start(1, 1, n1);
	while(q--)
	{
		int p1, p2;
		scanf("%d%d", &p1, &p2);
		sta[1]=sta[2]=sta[3]=sta[4]=inf;
		sta[0]=0;
		czyt(1, 1, n1, p1, p2);
		if (sta[4]<inf)
			printf("%d\n", sta[4]);
		else
			printf("-1\n");
	}
	return 0;
}