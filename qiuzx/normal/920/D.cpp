#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 5010
using namespace std;
ll n,k,v,a[N],dp[N][N],lst[N][N],cur;
vector<ll> seq,seq2;
void print_path(ll x,ll md)
{
	if(x<0)
	{
		return;
	}
	if(lst[x][md])
	{
		seq.push_back(x);
		print_path(x-1,(md+k-(a[x]%k))%k);
	}
	else
	{
		seq2.push_back(x);
		print_path(x-1,md);
	}
	return;
}
int main(){
// 	freopen("vento.in","r",stdin);
// 	freopen("vento.out","w",stdout);
	ll T,i,j;
	T=1;
	while(T--)
	{
		ll smsm=0;
		scanf("%d%d%d",&n,&k,&v);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			smsm+=a[i];
		}
		if(smsm<v)
		{
			puts("NO");
			continue;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<=k;j++)
			{
				dp[i][j]=-INF,lst[i][j]=-1;
			}
		}
		dp[0][0]=0,lst[0][0]=0;
		dp[0][a[0]%k]=a[0],lst[0][a[0]%k]=1;
		for(i=1;i<n;i++)
		{
			for(j=0;j<=k;j++)
			{
				if(dp[i][j]<dp[i-1][j])
				{
					dp[i][j]=dp[i-1][j];
					lst[i][j]=0;
				}
				if(dp[i][(j+a[i])%k]<dp[i-1][j]+a[i])
				{
					dp[i][(j+a[i])%k]=dp[i-1][j]+a[i];
					lst[i][(j+a[i])%k]=1;
				}
			}
		}
		if(dp[n-1][v%k]<0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		seq.clear();
		seq2.clear();
		print_path(n-1,v%k);
		vector<pair<ll,pair<ll,ll> > > ans;
		for(i=1;i<seq.size();i++)
		{
			ans.push_back(make_pair(INF,make_pair(seq[i],seq[0])));
			a[seq[0]]+=a[seq[i]];
			a[seq[i]]=0;
		}
		for(i=1;i<seq2.size();i++)
		{
			ans.push_back(make_pair(INF,make_pair(seq2[i],seq2[0])));
			a[seq2[0]]+=a[seq2[i]];
			a[seq2[i]]=0;
		}
		if(seq.empty())
		{
			if(v>0)
			{
				for(i=0;i<n;i++)
				{
					if(a[i]==0)
					{
						ans.push_back(make_pair(v/k,make_pair(seq2[0],i)));
						break;
					}
				}
			}
		}
		else if(seq2.empty())
		{
			if(smsm>v)
			{
				for(i=0;i<n;i++)
				{
					if(a[i]==0)
					{
						ans.push_back(make_pair((smsm-v)/k,make_pair(seq[0],i)));
						break;
					}
				}
			}
		}
		else
		{
			if(a[seq[0]]<v)
			{
				ans.push_back(make_pair((v-a[seq[0]])/k,make_pair(seq2[0],seq[0])));
			}
			else if(a[seq[0]]>v)
			{
				ans.push_back(make_pair((a[seq[0]]-v)/k,make_pair(seq[0],seq2[0])));
			}
		}
// 		printf("%d\n",ans.size());
		for(i=0;i<ans.size();i++)
		{
			printf("%d %d %d\n",ans[i].F,ans[i].S.F+1,ans[i].S.S+1);
		}
	}
	return 0;
}