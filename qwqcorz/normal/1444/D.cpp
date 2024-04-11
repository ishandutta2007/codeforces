#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}
bool A[N],B[N];
int a[N],b[N];
bool check(int n,int *a,bool *c)
{
	bitset<N*N/2>dp[n+1];
	int sum=0;
	dp[0].set(0);
	for (int i=1;i<=n;i++) dp[i]=dp[i-1]|dp[i-1]<<a[i],sum+=a[i];
	if (sum&1) return 0;
	if (!dp[n][sum/=2]) return 0;
	for (int i=n;i>=1;i--) if (!dp[i-1][sum]) c[i]=1,sum-=a[i]; else c[i]=0;
	return 1;
}
void GunsNRoses()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int m=read();
	for (int i=1;i<=m;i++) b[i]=read();
	bool flag=n==m&&check(n,a,A)&&check(m,b,B);
	if (flag) puts("Yes");
		 else return void(puts("No"));
	vector<int>u[2],v[2];
	for (int i=1;i<=n;i++) if (A[i]) u[0].push_back(a[i]); else u[1].push_back(-a[i]);
	for (int i=1;i<=m;i++) if (B[i]) v[0].push_back(b[i]); else v[1].push_back(-b[i]);
	vector<pair<int,int>>ans;
	if (u[0].size()<=v[0].size())
	{
		sort(u[0].begin(),u[0].end(),greater<int>());
		sort(u[1].begin(),u[1].end());
		sort(v[0].begin(),v[0].end());
		sort(v[1].begin(),v[1].end(),greater<int>());
		u[0].insert(u[0].end(),u[1].begin(),u[1].end());
		v[0].insert(v[0].end(),v[1].begin(),v[1].end());
		for (int i=0;i<n;i++)
			ans.push_back(make_pair(u[0][i],0)),
			ans.push_back(make_pair(0,v[0][i]));
	}
	else
	{
		sort(u[0].begin(),u[0].end());
		sort(u[1].begin(),u[1].end(),greater<int>());
		sort(v[0].begin(),v[0].end(),greater<int>());
		sort(v[1].begin(),v[1].end());
		u[0].insert(u[0].end(),u[1].begin(),u[1].end());
		v[0].insert(v[0].end(),v[1].begin(),v[1].end());
		for (int i=0;i<n;i++)
			ans.push_back(make_pair(0,v[0][i])),
			ans.push_back(make_pair(u[0][i],0));
	}
	int x=0,y=0;
	for (auto i:ans) print(x+=i.first,' '),print(y+=i.second);
}

signed main()
{
	int T=read();
	while (T--) GunsNRoses();
	
	return 0;
}