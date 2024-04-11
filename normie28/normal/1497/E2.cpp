#include<bits/stdc++.h>
#define mii map<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define int long long
#define ii pair<int,int>
#define loop(i,a,b) for(int i=(a);i<(b);i++)
#define rloop(i,a,b) for(int i=(a);i>(b);i--)
#define tr(it,c) for(decltype((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
#define mod 998244353
#define mod2 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define SYNC ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PI 3.1415926535
#define double long double
 
using namespace std;
 
 
 
/***************************************************************************************************************************************************************/
 
 
 
 
 
int *lpd;
 
int *sieve(int n)
{
	int *lpf=new int[n+1];
	for(int i=1;i<=n;i++)
	lpf[i]=i;
	int rt=(int)floor(sqrt(n))+1;
	loop(i,2,n)
	{
		if(lpf[i]!=i)
		continue;
		for(int j=i;j<=n;j+=i)
		{
			if(lpf[j]==j)
			lpf[j]=i;
		}
	}
	return lpf;
}
 
int change(int x)
{
	map<int,int> m;
	while(x!=1)
	{
		m[lpd[x]]++;
		x/=lpd[x];
	}
	int res=1;
	tr(it,m)
	{
		if(it->sd&1)
		res*=it->ft;
	}
	return res;
}
 
void solve()	
{
	int n,k;
	cin>>n>>k;
	int a[n];
	loop(i,0,n)
	cin>>a[i];
	
	map<int,int> m;
	int next[n];
	rloop(i,n-1,-1)
	{
		a[i]=change(a[i]);
		next[i]=n;
		if(m.find(a[i])!=m.end())
		next[i]=m[a[i]];
		m[a[i]]=i;
	}
	
	int r[k+1];
	loop(i,0,k+1)
	r[i]=n;
	int dp[n+1][k+1];
	mem(dp,0);
	rloop(i,n-1,-1)
	{
		int z=next[i]-1;
		int temp[k+1],pt=0;
		while(pt!=k+1)
		{
			if(z<r[pt])
			{
				temp[pt++]=z;
				break;
			}
			temp[pt]=r[pt];
			pt++;
		}
		while(pt!=k+1)
		{
			temp[pt]=r[pt-1];
			pt++;
		}
		loop(j,0,k+1)
		r[j]=temp[j];
		
		loop(j,0,k+1)
		{
			dp[i][j]=mod;
			loop(x,0,j+1)
			{
				if(r[x]==n)
				dp[i][j]=0;
				else
				dp[i][j]=min(dp[i][j],1+dp[r[x]+1][j-x]);
			}
		}
	}
	
	cout<<max(1ll,dp[0][k]);
}
 
 
 
signed main()
{
	
	SYNC;
	lpd=sieve(1e7);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t=1;
	cin>>t;
	loop(i,1,t+1)
	{
		//cout<<"Case #"<<i<<": ";
		solve();
		cout<<"\n";
	}
}