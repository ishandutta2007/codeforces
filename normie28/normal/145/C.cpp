#include<bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1010;
ll n,b,i,j,m,c,d,k,t,t1,x,y,dp[3000][3000],a[3000],fac[100001];
vector<int> pool,bag;
ll bow (int a, int x)
{
	if (!x) return 1;
	ll r=bow(a,x/2);
	r*=r;
	r%=MOD;
	if (x%2) r*=a;
	return r%MOD;
}
int lucky(int k)
{
	while (k)
	{
		if (!((k%10==4)or(k%10==7))) return 0;
		k/=10;
	}
	return 1;
}
ll co (int k, int n)
{
	ll res= fac[n]*bow(fac[n-k],MOD-2);
	res%=MOD; 
	res*=bow(fac[k],MOD-2);
	return res%MOD;
}
int main() {
	fio;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		cin>>k;
		if (lucky(k))
		{
			pool.push_back(k);
		}
		else c++;
	}
	sort(pool.begin(),pool.end());
	k=0;
	a[0]=1;
	for (i=1;i<pool.size();i++)
	{
		if (pool[i]-pool[i-1]) k++;
		a[k]++;
	}
	k++;
	if (pool.size()==0) k--;
	for (i=0;i<=k;i++) dp[i][0]=1;
	for (i=1;i<=k;i++) for (j=1;j<=k;j++)
	{
		dp[i][j]=dp[i-1][j-1]*a[i-1]+dp[i-1][j];
		dp[i][j]%=MOD;
	}
	ll res=0;
	fac[0]=1;
	for(i=1;i<=100000;i++) fac[i]=(fac[i-1]*i)%MOD;
//	cout<<k<<endl;
	for (i=0;i<=m;i++) if ((i<=k)and(m-i<=c))
	{
//		cout<<i<<' '<<m-i<<' '<<c<<endl;
		res+=dp[k][i]*co(m-i,c);
		res%=MOD;
	}
	cout<<res;
}