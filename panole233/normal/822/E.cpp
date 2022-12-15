#include<bits/stdc++.h>
using namespace std;

#define fi first.first
#define se first.second
#define th second
int h[200001],f[200001][20],n,m,tmp,x,dp[100001][31],sq[101],Rk[200001],cnt,po[200001],lo[200001];
pair<pair<int,int>,int> rk[200001];
char s[200001],S[100001];

int lcp(int p,int q)
{
	int x=Rk[p],y=Rk[n-m+q];
	if (x>y) tmp=x,x=y,y=tmp;
	y--; int len=lo[y-x+1];
	return min(n-m-p,min(f[x][len],f[y-(1<<len)+1][len]));
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=200000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d",&n),scanf("%s",s);
	scanf("%d",&m),scanf("%s",S);
	scanf("%d",&x),n+=m;
	for (int i=n-m; i<n; i++) s[i]=S[i-n+m];
	for (int i=0; i<n; i++) sq[s[i]-'a']=1;
	for (int i=1; i<26; i++) sq[i]+=sq[i-1];
	for (int i=0; i<n; i++) rk[i].fi=sq[s[i]-'a'];
	for (int nw=1; nw<n; nw<<=1)
	{
		for (int i=0; i<n-nw; i++) rk[i].se=rk[i+nw].fi,rk[i].th=i;
		for (int i=n-nw; i<n; i++) rk[i].se=0,rk[i].th=i;
		sort(rk,rk+n),cnt=0;
		for (int i=0; i<n; i++)
		{
			if (i==0||rk[i].fi!=rk[i-1].fi||rk[i].se!=rk[i-1].se) cnt++;
			Rk[rk[i].th]=cnt;
		}
		for (int i=0; i<n; i++) rk[i].fi=Rk[i];
	}
	for (int i=0; i<n; i++) po[Rk[i]]=i;
	for (int i=0; i<n; i++)
	{
		if (Rk[i]==n) h[i]=0; else
		{
			h[i]=max(h[i-1]-1,0);
			while (s[i+h[i]]==s[po[Rk[i]+1]+h[i]]) h[i]++;
		}
		f[Rk[i]][0]=h[i];
	}
	for (int j=1; j<=19; j++)
		for (int i=1; i<=n; i++)
			if (i+(1<<j)-1<=n)
				f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	int l=lcp(0,0);
	if (l) dp[l-1][1]=l;
	for (int i=0; i<n-m-1; i++)
	{
		for (int j=0; j<=x; j++)
			if (dp[i][j]==m) {puts("YES"); return 0;}
		for (int j=0; j<x; j++)
		{
			l=lcp(i+1,dp[i][j]);
			if (l) dp[i+l][j+1]=max(dp[i+l][j+1],dp[i][j]+l);
		}
		for (int j=0; j<=x; j++) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
	}
	for (int j=0; j<=x; j++)
		if (dp[n-m-1][j]==m) {puts("YES"); return 0;}
	puts("NO");
	return 0;
}