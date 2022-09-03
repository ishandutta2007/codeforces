#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;

const int maxn=4111;
const int mod=1e9+7;
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}

char s[maxn];
int p,k,l,d[maxn],tot,a[maxn];
int dp[maxn][2][2],ndp[maxn][2][2];

int get_ways(int sum)
{
	if(sum<p)return sum+1;
	else return p+p-sum-1;
}

int main()
{
	scanf("%d%d%s",&p,&k,s);l=strlen(s);
	for(int i=0;i<l;i++)d[i]=s[l-i-1]-'0';
	
	tot=0;
	while(l)
	{
		LL rem=0;
		for(int i=l-1;i>=0;i--)
		{
			rem=rem*10+d[i];
			d[i]=rem/p;
			rem%=p;
		}
		a[tot++]=rem;
		while(l&&d[l-1]==0)l--;
	}
	if(tot<k)
	{
		puts("0");
		return 0;
	}
	reverse(a,a+tot);
	dp[0][0][0]=1;
	for(int i=0;i<tot;i++)
	{
		memset(ndp,0,sizeof(ndp));
		for(int j=0;j<tot;j++)for(int c=0;c<2;c++)for(int diff=0;diff<2;diff++)if(dp[j][c][diff])
		{
	//		printf("i= %d j= %d c= %d diff= %d dp= %d\n",i,j,c,diff,dp[i][j][c][diff]);
			for(int nc=0;nc<2;nc++)
			{
				int lv=max(0,c*p-nc),rv=min(p+p-2,(diff?c*p+p-1-nc:c*p+a[i]-nc));
				if(lv>rv)continue;
				int vl=get_ways(lv),vr=get_ways(rv),vsum=(LL)(vl+vr)*(rv-lv+1)%mod*(mod+1)/2%mod;
				add(ndp[j+nc][nc][1],(LL)dp[j][c][diff]*(vsum-vr+mod)%mod);
				add(ndp[j+nc][nc][diff|(rv!=c*p+a[i]-nc)],(LL)dp[j][c][diff]*vr%mod);
			}
		}
		memcpy(dp,ndp,sizeof(dp));
	}
	
	int ans=0;
	for(int j=k;j<=tot;j++)
	{
		add(ans,dp[j][0][0]);
		add(ans,dp[j][0][1]);
	}
	printf("%d\n",ans);
	return 0;
}