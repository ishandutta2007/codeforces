#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<pair<int,int> > v[4000001];
int n,m,r,c,f[2001][2001],x,y,ans,dx[4],dy[4];
bool bo[2002][2002];
char s[2001];

int main()
{
	dx[0]=dx[1]=dy[2]=dy[3]=0;
	dx[2]=dy[0]=1; dx[3]=dy[1]=-1;
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	memset(bo,0,sizeof(bo));
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s);
		for (int j=0; j<m; j++)
			if (s[j]=='.') bo[i][j+1]=1;
	}
	for (int i=0; i<=4000000; i++) v[i].clear();
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) f[i][j]=x+1;
	f[r][c]=0; v[0].push_back(make_pair(r,c));
	for (int i=0; i<=4000000; i++)
	{
		for (int j=0; j<v[i].size(); j++)
		{
			int x=v[i][j].first,y=v[i][j].second,X,Y;
			if (f[x][y]<i) continue;
			for (int k=0; k<4; k++)
			{
				X=x+dx[k]; Y=y+dy[k];
				if (!bo[X][Y]) continue;
				if (f[X][Y]>f[x][y]+(k==1?1:0)) f[X][Y]=f[x][y]+(k==1?1:0),v[f[X][Y]].push_back(make_pair(X,Y));
			}
		}
	}
	ans=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (f[i][j]<=x&&f[i][j]+j-c<=y) ans++;
	printf("%d\n",ans);
	return 0;
}