#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int maxn=10005;
typedef long long LL;
LL a,fac[maxn];
int dp[maxn][2];
unordered_map<LL,int> hs;
vector<pair<LL,int> > upd;
void fun(int id)
{
	LL x=fac[id]-1;
	if(x<2)return;
	for(LL i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			while(x%i==0)x/=i;
			if(x==1)upd.pb(mp(i,id));
			return;
		}
	}
	upd.pb(mp(x,id));
}
int main()
{
	cin>>a;
	int cnt=0;
	for(LL i=1;i*i<=a;i++)
		if(a%i==0)
		{
			fac[++cnt]=i;
			if(a/i!=i)fac[++cnt]=a/i;
		}
	sort(fac+1,fac+cnt+1);
	for(int i=1;i<=cnt;i++)
		hs[fac[i]]=i;
	dp[1][0]=1;
	for(int i=1;i<=cnt;++i)
		fun(i);
	sort(upd.begin(),upd.end());
	int cur=0;
	LL t;
	int tid;
	for(int i=0;i<upd.size();i++)
	{
		if(i==0||upd[i].ff!=upd[i-1].ff)
		{
			cur^=1;
			for(int j=1;j<=cnt;j++)dp[j][cur]=dp[j][cur^1];
		}
		for(int j=1;j<=cnt;j++)
		{
			t=fac[j]*fac[upd[i].ss];
			tid=hs[t];
			if(tid==0)continue;
			dp[tid][cur]+=dp[j][cur^1];
		}
	}
	printf("%d\n",dp[cnt][cur]);
	return 0;
}