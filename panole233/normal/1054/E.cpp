#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,len,ans[1000001][4],an;
vector<char> s[301][301],t[301][301];
char S[100001];

void move(int x,int y,int X,int Y,char c)
{
	if (x==X&&y==Y) return;
	if (x<X) 
	{
		if (y<=Y)
		{
			if (y<Y) ans[++an][0]=x,ans[an][1]=y,ans[an][2]=x,ans[an][3]=Y,s[x][Y].push_back(c);
			else ans[++an][0]=x,ans[an][1]=y,ans[an][2]=X,ans[an][3]=Y;
		}
		else ans[++an][0]=x,ans[an][1]=y,ans[an][2]=x,ans[an][3]=Y,ans[++an][0]=x,ans[an][1]=Y,ans[an][2]=X,ans[an][3]=Y; 
	} else
	ans[++an][0]=x,ans[an][1]=y,ans[an][2]=X,ans[an][3]=Y;
}

void Move(int x,int y,int X,int Y)
{
	if (x==X&&y==Y) return;
	if (x!=X)
	{
		if (y>=Y)
		{
			if (y>Y) ans[++an][0]=x,ans[an][1]=y,ans[an][2]=x,ans[an][3]=Y;
			ans[++an][0]=x,ans[an][1]=Y,ans[an][2]=X,ans[an][3]=Y;
		} 
		else ans[++an][0]=x,ans[an][1]=y,ans[an][2]=X,ans[an][3]=y,ans[++an][0]=X,ans[an][1]=y,ans[an][2]=X,ans[an][3]=Y;
	}
	else ans[++an][0]=x,ans[an][1]=y,ans[an][2]=X,ans[an][3]=Y;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			s[i][j].clear();
			scanf("%s",S); len=strlen(S);
			for (int k=len-1; k>=0; k--) s[i][j].push_back(S[k]);
		}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		{
			t[i][j].clear();
			scanf("%s",S); len=strlen(S);
			for (int k=len-1; k>=0; k--) t[i][j].push_back(S[k]);
		}
	an=0; int siz1=s[n][m-1].size(),siz2=s[n][m].size();
	for (int i=0; i<siz1; i++)
		if (s[n][m-1][i]=='0') ans[++an][0]=n,ans[an][1]=m-1,ans[an][2]=n-1,ans[an][3]=m-1,s[n-1][m-1].push_back('0');
		else ans[++an][0]=n,ans[an][1]=m-1,ans[an][2]=n,ans[an][3]=m;
	for (int i=0; i<siz2; i++)
		if (s[n][m][i]=='1') ans[++an][0]=n,ans[an][1]=m,ans[an][2]=n-1,ans[an][3]=m,s[n-1][m].push_back('1');
		else ans[++an][0]=n,ans[an][1]=m,ans[an][2]=n,ans[an][3]=m-1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (i<n||j<m-1)
				for (int k=0; k<s[i][j].size(); k++)
					if (s[i][j][k]=='0') move(i,j,n,m-1,'0'); else move(i,j,n,m,'1');
	for (int i=0; i<t[n][m-1].size(); i++)
		if (t[n][m-1][i]=='0') Move(n,m-1,n-1,m-1),Move(n-1,m-1,n,m-1);
		else Move(n,m,n,m-1);
	for (int i=0; i<t[n][m].size(); i++)
		if (t[n][m][i]=='1') Move(n,m,n-1,m),Move(n-1,m,n,m);
		else Move(n,m-1,n,m);
	for (int i=1; i<=n; i++)
	{
		if (i<n)
		{
			for (int j=0; j<t[i][m].size(); j++)
				if (t[i][m][j]=='0') Move(n,m-1,i,m-1);
			for (int j=0; j<t[i][m-1].size(); j++)
				if (t[i][m-1][j]=='0') Move(n,m-1,i,m-1); else
				{
					ans[++an][0]=n,ans[an][1]=m,ans[an][2]=i,ans[an][3]=m;
					ans[++an][0]=i,ans[an][1]=m,ans[an][2]=i,ans[an][3]=m-1;
				}
			for (int j=0; j<t[i][m].size(); j++)
				if (t[i][m][j]=='0') Move(i,m-1,i,m); else Move(n,m,i,m);
		}
		for (int j=1; j<m-1; j++)
			for (int k=0; k<t[i][j].size(); k++)
				if (t[i][j][k]=='0') Move(n,m-1,i,j); else Move(n,m,i,j);
	}
	printf("%d\n",an);
	for (int i=1; i<=an; i++) printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
	return 0;
}