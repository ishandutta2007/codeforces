#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll star[100001];
struct seg
{
	ll val[100001],lazy[100001];
	void reset(ll l, ll r, ll cur)
	{
		lazy[cur]=0;
		if (l==r)
		{
			val[cur]=star[l];
		}
		else
		{
			ll mid=(l+r)/2;
			reset(l,mid,(cur<<1));
			reset(mid+1,r,(cur<<1)+1);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
	void flusha(ll cur)
	{
		val[(cur<<1)]+=lazy[cur];
		val[(cur<<1)+1]+=lazy[cur];
		lazy[(cur<<1)]+=lazy[cur];
		lazy[(cur<<1)+1]+=lazy[cur];
		lazy[cur]=0;
	}
	void update(ll l, ll r, ll cur, ll tl, ll tr, ll d)
	{
		if ((tl>r)or(tr<l)) return;
		else if ((tl<=l)and(tr>=r))
		{
			val[cur]+=d;
			lazy[cur]+=d;
		}
		else
		{
			ll mid=(l+r)/2;
			flusha(cur);
			update(l,mid,(cur<<1),tl,tr,d);
			update(mid+1,r,(cur<<1)+1,tl,tr,d);
			val[cur]=max(val[(cur<<1)],val[(cur<<1)+1]);
		}
	}
};
seg st;
ll dp[51][20001];
ll val[51][20001];
ll pre[51][20001];
ll n,m,k,t,t1,i,j,u,v,a,b,res;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	for (j=1;j<=m;j++)
	{
		cin>>val[i][j];
		pre[i][j]=pre[i][j-1]+val[i][j];
	}
	for (i=1;i<=n;i++)
	{
		if (i==1)
		{
			for (j=1;j<=m-k+1;j++) 
			{			
			dp[i][j]=pre[i][j+k-1]-pre[i][j-1]; 
				if (i==n) res=max(res,dp[i][j]);
//				cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		}
		else
		{
			for (j=1;j<=m-k+1;j++) 
			{
			star[j]=pre[i][j+k-1]-pre[i][max(j-1,k)]+dp[i-1][j]; 
//			cout<<star[j]<<' ';
			}
	//		cout<<endl;
			st.reset(1,m-k+1,1);
			for (j=1;j<=m-k+1;j++)
			{
	//			cout<<st.val[1]<<' ';
				dp[i][j]=st.val[1]+pre[i][j+k-1]-pre[i][j-1];
				if (j<m-k+1)
				{
					st.update(1,m-k+1,1,j-k+1,j,val[i][j]);
					st.update(1,m-k+1,1,j+1,j+k,-val[i][j+k]);
				}
				if (i==n) res=max(res,dp[i][j]);
		//		cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			}
		}
	}
	cout<<res;
	
}