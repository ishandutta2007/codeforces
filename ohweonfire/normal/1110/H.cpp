// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=20111;
const int N=10;

int go[maxn][10],tot,rt;
int q[maxn],fr,rr,fail[maxn],n,m,l;
int wild[maxn][811];

void construct()
{
	fr=rr=0;q[rr++]=rt;
	for(;fr<rr;fr++)
	{
		int x=q[fr];
		for(int i=0;i<N;i++)if(go[x][i])
		{
			int&f=fail[go[x][i]];
			if(x==rt)f=x;
			else
			{
				f=fail[x];
				while(f!=rt&&!go[f][i])f=fail[f];
				if(go[f][i])f=go[f][i];
			}
			q[rr++]=go[x][i];
		}
	}
	for(int i=0;i<N;i++)if(!go[rt][i])go[rt][i]=rt;
	for(int _=1;_<rr;_++)
	{
		int x=q[_];
		for(int i=0;i<N;i++)if(!go[x][i])go[x][i]=go[fail[x]][i];
	}
}
void insert(char*s)
{
	int cur=rt;
	for(int i=0;s[i];i++)
	{
		if(!go[cur][s[i]-'0'])go[cur][s[i]-'0']=++tot;
		cur=go[cur][s[i]-'0'];
	}
}
char s[1111],t[1111];

int dp[2111][maxn];
void do_dp()
{
	/*for(int i=2;i<=2;i++)
	{
		printf("i= %d\n",i);
		for(int j=0;j<N;j++)printf("go %d = %d\n",j,go[i][j]);
		printf("wc ");for(int j=0;j<m;j++)printf("%d ",wild[i][j]);
		puts("");
	}*/
	for(int i=1;i<=tot;i++)dp[0][i]=wild[i][0];
	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=tot;j++)
		{
			for(int k=0;k<N;k++)dp[i][j]=max(dp[i][j],dp[i-1][go[j][k]]);
			dp[i][j]+=wild[j][min(i,m-1)];
//			printf("i= %d j= %d dp= %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",dp[l][rt]);
	int cur=rt;
	for(int i=l;i>=1;i--)
	{
		int val=dp[i][cur]-wild[cur][min(i,m-1)];
		for(int nxt=0;nxt<N;nxt++)if(dp[i-1][go[cur][nxt]]==val)
		{
			putchar(nxt+'0');
			cur=go[cur][nxt];
			break;
		}
	}
	puts("");
}

int main()
{
	scanf("%s%s%d",s,t,&l);
	n=strlen(s);m=strlen(t);
	
	rt=++tot;
	insert(s);insert(t);
	
	if(n==m)
	{
		int k1=rt,k2=rt;
		for(int i=0;i<n;i++)
		{
			if(k1==k2&&s[i]!=t[i])
			{
				for(int c=s[i]+1;c<t[i];c++)
				{
					if(!go[k1][c-'0'])go[k1][c-'0']=++tot;
					wild[go[k1][c-'0']][n-i-1]++;
				}
			}
			else if(k1!=k2)
			{
				for(int c=s[i]+1;c<'0'+N;c++)
				{
					if(!go[k1][c-'0'])go[k1][c-'0']=++tot;
					wild[go[k1][c-'0']][n-i-1]++;
				}
				for(int c='0'+(i==0);c<t[i];c++)
				{
					if(!go[k2][c-'0'])go[k2][c-'0']=++tot;
					wild[go[k2][c-'0']][n-i-1]++;
				}
			}
			k1=go[k1][s[i]-'0'];k2=go[k2][t[i]-'0'];
		}
		wild[k1][0]++;
		if(k1!=k2)wild[k2][0]++;
	}
	else
	{
		int k1=rt,k2=rt;
		for(int i=0;i<n;i++)
		{
			for(int c=s[i]+1;c<'0'+N;c++)
			{
				if(!go[k1][c-'0'])go[k1][c-'0']=++tot;
				wild[go[k1][c-'0']][n-i-1]++;
			}
			k1=go[k1][s[i]-'0'];
		}
		for(int i=0;i<m;i++)
		{
			for(int c='0'+(i==0);c<t[i];c++)
			{
				if(!go[k2][c-'0'])go[k2][c-'0']=++tot;
				wild[go[k2][c-'0']][m-i-1]++;
			}
			k2=go[k2][t[i]-'0'];
		}
		wild[k1][0]++;
		wild[k2][0]++;
		for(int i=1;i<N;i++)
		{
			int&k=go[rt][i];if(!k)k=++tot;
			for(int j=n+1;j<m;j++)
			{
				wild[k][j-1]++;
			}
		}
	}
	
	construct();
	for(int i=1;i<rr;i++)
	{
		int x=q[i];
		for(int j=0;j<m;j++)wild[x][j]+=wild[fail[x]][j];
	}
	for(int i=1;i<=tot;i++)for(int j=1;j<m;j++)wild[i][j]+=wild[i][j-1];
	
	do_dp();
	return 0;
}