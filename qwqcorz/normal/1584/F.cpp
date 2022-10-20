#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10;
const int M=55;
const int S=1<<N;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline bool ckmx(int &x,int y){if (x<y) return x=y,1;return 0;}
int a[N][M*2];
char c[N][M*2],s[N*M*2];
int len[N],dp[M][S];
pair<int,int>from[M][S];
int pos[N][M][2],tot[N][M],b[N][M*2],nxt[N][M*2][M];
void Ramones()
{
	memset(dp,-1,sizeof(dp));
	memset(pos,0,sizeof(pos));
	memset(tot,0,sizeof(tot));
	memset(b,0,sizeof(b));
	int n=read(),cnt=0;
	for (int i=0;i<n;i++) scanf("%s",c[i]),len[i]=strlen(c[i]);
	for (int i=0;i<n;i++)
	for (int j=0;j<len[i];j++) s[cnt++]=c[i][j];
	sort(s,s+cnt);
	cnt=unique(s,s+cnt)-s;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<len[i];j++) a[i][j]=lower_bound(s,s+cnt,c[i][j])-s;
		for (int j=0;j<len[i];j++) pos[i][a[i][j]][b[i][j]=tot[i][a[i][j]]++]=j;
		memset(nxt[i][len[i]],-1,sizeof(nxt[i][len[i]]));
		for (int j=len[i]-1;j>=0;j--)
		{
			memcpy(nxt[i][j],nxt[i][j+1],sizeof(nxt[i][j]));
			nxt[i][j][a[i][j]]=j;
		}
	}
	for (int j=0;j<cnt;j++)
	{
		int S=0;
		for (int i=0;i<n;i++)
		if (~nxt[i][0][j]) S|=b[i][nxt[i][0][j]]<<i;
					  else{S=-1;break;}
		if (~S) dp[j][S]=1,from[j][S]=make_pair(-1,-1);
	}
	vector<pair<int,int>>p;
	for (int i=0;i<cnt;i++)
	for (int j=0;j<(1<<n);j++)
	p.push_back(make_pair(i,j));
	sort(p.begin(),p.end(),[&](pair<int,int>x,pair<int,int>y){return pos[0][x.first][x.second&1]<pos[0][y.first][y.second&1];});
	int ans=0,x=-1,y=-1;
	for (auto tmp:p)
	{
		int i=tmp.first,j=tmp.second;
		if (dp[i][j]<0) continue;
		if (ckmx(ans,dp[i][j])) x=i,y=j;
		for (int k=0;k<cnt;k++)
		{
			int S=0;
			for (int t=0;t<n;t++)
			if (~nxt[t][pos[t][i][j>>t&1]+1][k]) S|=b[t][nxt[t][pos[t][i][j>>t&1]+1][k]]<<t;
											else{S=-1;break;}
			if (~S) if (ckmx(dp[k][S],dp[i][j]+1)) from[k][S]=make_pair(i,j);
		}
	}
	print(ans);
	vector<int>c;
	while (~x)
	{
		c.push_back(x);
		auto tmp=from[x][y];
		x=tmp.first,y=tmp.second;
	}
	reverse(c.begin(),c.end());
	for (int i:c) putchar(s[i]);
	putchar('\n');
}

signed main()
{
	int T=read();
	while (T--) Ramones();
	
	return 0;
}