#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
inline int mex(vector<int>&a)
{
	static bool vis[4];
	memset(vis,0,sizeof(vis));
	for (int i:a) vis[i]=1;
	for (int i=0;i<4;i++) if (!vis[i]) return i;
	return -1;
}
int pre[6][6][6],len[6][6][6];
vector<vector<int>>sg[6][6][6];
void solve(vector<vector<int>>&s,int x,int y,int z)
{
	map<vector<vector<int>>,int>mp;
	s.push_back(vector<int>({0,0,0}));
	for (int i=1;;i++)
	{
		s.push_back(vector<int>());
		vector<int>tmp;
		tmp.push_back(s[max(i-x,0)][0]);
		tmp.push_back(s[max(i-y,0)][1]);
		tmp.push_back(s[max(i-z,0)][2]);
		s.back().push_back(mex(tmp));
		tmp.clear();
		tmp.push_back(s[max(i-x,0)][0]);
		tmp.push_back(s[max(i-z,0)][2]);
		s.back().push_back(mex(tmp));
		tmp.clear();
		tmp.push_back(s[max(i-x,0)][0]);
		tmp.push_back(s[max(i-y,0)][1]);
		s.back().push_back(mex(tmp));
		if (i>=5)
		{
			vector<vector<int>>now;
			for (int j=i-5;j<i;j++) now.push_back(s[j]);
			if (mp.count(now))
			{
				pre[x][y][z]=mp[now];
				len[x][y][z]=i-mp[now];
				return;
			}
			mp[now]=i;
		}
	}
}
int getSG(int x,int y,int z,ll a,int b)
{
	if (a<pre[x][y][z]) return sg[x][y][z][a][b];
	return sg[x][y][z][(a-pre[x][y][z])%len[x][y][z]+pre[x][y][z]][b];
}
ll a[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	for (int i=1;i<=5;i++)
	for (int j=1;j<=5;j++)
	for (int k=1;k<=5;k++)
	solve(sg[i][j][k],i,j,k);
	int T=read();
	while (T--)
	{
		int n=read(),x=read(),y=read(),z=read(),sum=0,ans=0;
		for (int i=1;i<=n;i++) sum^=getSG(x,y,z,a[i]=read(),0);
		for (int i=1;i<=n;i++) if (!(sum^getSG(x,y,z,a[i],0)^getSG(x,y,z,max(a[i]-x,0LL),0))) ans++;
		for (int i=1;i<=n;i++) if (!(sum^getSG(x,y,z,a[i],0)^getSG(x,y,z,max(a[i]-y,0LL),1))) ans++;
		for (int i=1;i<=n;i++) if (!(sum^getSG(x,y,z,a[i],0)^getSG(x,y,z,max(a[i]-z,0LL),2))) ans++;
		print(ans);
	}
	
	return 0;
}