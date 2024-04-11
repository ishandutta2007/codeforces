#include<cstdio>
#include<cstring>

int a[201][201],ans,T,x,y,n,m,eden;
bool bo[201][201],bb,bbb;

int read()
{
	int pjy=0,flag=1; char ch;
	while (ch>'9'||ch<'0') {if (ch=='-') flag=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') pjy=pjy*10+ch-48,ch=getchar();
	return pjy;
}

void dfs(int x)
{
	if (((x==eden)||(a[x][0]&1))&&bbb) {bb=1; return;}
	bbb=1;
	for (int i=1; i<=a[x][0]; i++)
		if (!bo[x][a[x][i]]) 
		{
			bo[x][a[x][i]]=bo[a[x][i]][x]=1; 
			dfs(a[x][i]);
			if (!bb) bo[x][a[x][i]]=bo[a[x][i]][x]=0;
			else {printf("%d %d\n",x,a[x][i]); return;}
		}
}

int main()
{
	T=read();
	while (T--)
	{
		n=read(); m=read();
		memset(a,0,sizeof(a));
		for (int i=1; i<=m; i++) 
		{
			x=read(); y=read();
			a[x][++a[x][0]]=y;
			a[y][++a[y][0]]=x;
		}
		ans=0;
		memset(bo,0,sizeof(bo));
		for (int i=1; i<=n; i++)
			if (!(a[i][0]&1)) ans++;
		printf("%d\n",ans);
		for (int i=1; i<=n; i++)
			if (a[i][0]&1) 
				for (int j=1; j<=a[i][0]; j++)
					if (!bo[i][a[i][j]]) bbb=0,bb=0,eden=i,dfs(i);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=a[i][0]; j++)
				if (!bo[i][a[i][j]]) eden=i,bbb=0,bb=0,dfs(i);
	}
	return 0;
}