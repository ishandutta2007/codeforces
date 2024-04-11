#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
const int mod=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int pw[8],sum[7],cnt=0,ans=0,n;
vector<int>v[7];
void dfs0(int deep,int val)
{
	v[deep].push_back((cnt++-val+p)%p);
	if (deep<6) for (int i=0;i<=9;i++) dfs0(deep+1,val*10+i);
}
void dfs1(int deep,int val)
{
	static int idx=0;
	if (val>n) return;
	if (val*pw[6]>n/10&&(val+1)*pw[6]-1<=n)
	{
		for (int i=0;i<=6;i++)
		{
			int now=(idx-val%p*pw[i]%p+p)%p,siz=v[i].size();
			int tot=v[i].end()-lower_bound(v[i].begin(),v[i].end(),p-now);
			ans=(ans+sum[i]+now*siz-p*tot)%mod;
		}
		idx+=cnt;
		return;
	}
	ans=(ans+(idx++-val%p+p)%p)%mod;
	for (int i=!deep;i<=9;i++) dfs1(deep+1,val*10+i);
}
void Multi_test_no_horses()
{
	n=read();
	dfs0(0,0);
	for (int i=pw[0]=1;i<=7;i++) pw[i]=pw[i-1]*10;
	for (int i=0;i<=6;i++)
	{
		sort(v[i].begin(),v[i].end());
		for (int j:v[i]) sum[i]+=j;
	}
	dfs1(0,0);
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}