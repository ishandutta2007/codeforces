#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=2111;
const int mod=1e9+7;
const int mod2=998244353;
const int base=443;

inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}

namespace HS
{
	int pw[maxn],pw2[maxn];
	void prework()
	{
		pw[0]=pw2[0]=1;
		for(int i=1;i<maxn;i++)
		{
			pw[i]=(LL)pw[i-1]*base%mod;
			pw2[i]=(LL)pw2[i-1]*base%mod2;
		}
	}
	inline pii calhs(pii*hs,int l,int r)
	{
		return mp(((hs[r].ff-(LL)hs[l-1].ff*pw[r-l+1])%mod+mod)%mod,
		((hs[r].ss-(LL)hs[l-1].ss*pw2[r-l+1]%mod2+mod2)%mod2));
	}
	void construct(char*s,pii*hs,int n)
	{
		hs[0]=mp(0,0);
		for(int i=1;i<=n;i++)
		{
			hs[i]=mp(((LL)hs[i-1].ff*base+s[i]-'a'+1)%mod,((LL)hs[i-1].ss*base+s[i]-'a'+1)%mod2);
		}
	}
}

char s[2][maxn],rs[2][maxn],t[maxn];
int n,m;
pii hs[2][maxn],rhs[2][maxn],hst[maxn];

bool cal_front(int i,int j,int l)
{
	if(l%2)return false;l/=2;
	if(j<l)return false;
	return (HS::calhs(hs[i],j-l+1,j)==HS::calhs(hst,l+1,l+l)&&
			HS::calhs(rhs[i^1],n-j+1,n-j+l)==HS::calhs(hst,1,l));
}
bool cal_back(int i,int j,int l)
{
	if(l%2)return false;l/=2;
	if(l==0)return true;
	if(j+l>n+1)return false;
	return (HS::calhs(hs[i],j,j+l-1)==HS::calhs(hst,m-l-l+1,m-l)&&
			HS::calhs(rhs[i^1],n-j-l+2,n-j+1)==HS::calhs(hst,m-l+1,m));
}

int dp[2][maxn][maxn],ans;

void calc()
{
	memset(dp,0,sizeof(dp));
	for(int j=1;j<=n;j++)for(int i=0;i<2;i++)
	{
		dp[i][j][1]=1;
		for(int k=5;k<=m;k+=2)if(cal_front(i,j-1,k-1))
		{
//			printf("i= %d j= %d l= %d\n",i,j,k-1);
			add(dp[i][j][k],1);
		}
		for(int k=1;k<=m;k++)if(s[i][j]==t[k])
		{
//			printf("i= %d j= %d k= %d dp= %d\n",i,j,k,dp[i][j][k]);
			add(dp[i][j+1][k+1],dp[i][j][k]);
			if(s[i^1][j]==t[k+1])add(dp[i^1][j+1][k+2],dp[i][j][k]);
		}
	}
	for(int i=0;i<2;i++)for(int j=1;j<=n+1;j++)for(int k=1;k<=m+1;k++)
		if(cal_back(i,j,m-k+1)&&m-k+1!=2)
			add(ans,dp[i][j][k]);
}

int main()
{
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1);
	n=strlen(s[0]+1);m=strlen(t+1);
	
	if(m==1)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[0][i]==t[1])ans++;
			if(s[1][i]==t[1])ans++;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==2)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s[0][i]==t[1]&&s[0][i+1]==t[2])ans++;
			if(s[0][i]==t[1]&&s[0][i-1]==t[2])ans++;
			if(s[1][i]==t[1]&&s[1][i+1]==t[2])ans++;
			if(s[1][i]==t[1]&&s[1][i-1]==t[2])ans++;
			if(s[0][i]==t[1]&&s[1][i]==t[2])ans++;
			if(s[1][i]==t[1]&&s[0][i]==t[2])ans++;
		}
		printf("%d\n",ans);
		return 0;
	}
	
	memcpy(rs,s,sizeof(s));
	reverse(rs[0]+1,rs[0]+n+1);reverse(rs[1]+1,rs[1]+n+1);
	
	HS::prework();
	HS::construct(s[0],hs[0],n);
	HS::construct(s[1],hs[1],n);
	HS::construct(rs[0],rhs[0],n);
	HS::construct(rs[1],rhs[1],n);
	HS::construct(t,hst,m);
	
	calc();
	swap(s[0],rs[0]);swap(s[1],rs[1]);
	swap(hs[0],rhs[0]);swap(hs[1],rhs[1]);
	calc();
	
	printf("%d\n",ans);
	return 0;
}