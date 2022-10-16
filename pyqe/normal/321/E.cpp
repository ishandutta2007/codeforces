#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[4069][4069],ps[4069][4069],dp[869][4069];

void dnc(long long x,long long l,long long r,long long lh,long long rh)
{
	long long i,md=(lh+rh)/2,mn,e;
	pair<long long,long long> mne={1e18,-1};
	
	if(lh>rh)
	{
		return;
	}
	for(i=l;i<=min(r,md);i++)
	{
		mne=min(mne,{dp[x-1][i-1]+ps[i][md],i});
	}
	mn=mne.fr;
	e=mne.sc;
	dp[x][md]=mn;
	dnc(x,l,e,lh,md-1);
	dnc(x,e,r,md+1,rh);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long i,j,k;
	string s;
	
	cin>>n>>m;
	getline(cin,s);
	for(i=1;i<=n;i++)
	{
		getline(cin,s);
		for(j=1;j<=n;j++)
		{
			a[i][j]=s[(j-1)*2]-'0';
		}
	}
	for(i=n;i;i--)
	{
		for(j=i;j<=n;j++)
		{
			ps[i][j]=ps[i][j-1]+ps[i+1][j]-ps[i+1][j-1]+a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		dp[0][i]=1e18;
	}
	for(i=1;i<=m;i++)
	{
		dnc(i,1,n,1,n);
	}
	cout<<dp[m][n]<<"\n";
}