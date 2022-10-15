#include <bits/stdc++.h>
using namespace std;
#define MAGIC 450
#define N 200010
string s;
int n,sum[N];
int cnt[(MAGIC+1)*N];
int q[N];
long long calc(int x)
{
	return 1ll*x*(x-1)/2;
}
long long workSmall()
{
	long long ret=0;
	for(int now=1;now<=MAGIC;now++)
	{
		cnt[now*n]=1;
		for(int i=1;i<=n;i++)
		{
			int t=i-now*sum[i]+now*n;
			q[i]=t;
			cnt[t]++;
		}
		sort(q+1,q+n+1); ret+=calc(cnt[q[1]]);
		for(int i=2;i<=n;i++)if (q[i]!=q[i-1])ret+=calc(cnt[q[i]]);
		for(int i=1;i<=n;i++)cnt[q[i]]=0;
		cnt[now*n]=0;
	}
	return ret;
}
int nxt[N];
long long workBig()
{
	long long ret=0;
	int now=n+1;
	nxt[n+1]=n+1;
	for(int i=n;i;i--)
	{
		if(s[i]=='1')now=i;
		nxt[i]=now;
	}
 
	for(int i=1;i<=n;i++)
	{
		int now=nxt[i],cc=1;
		int j=1;
		while (now<=n && 1ll*j*MAGIC-1+i<=n)
		{
			long long len=(nxt[now+1]-i)/j;
			if (len>=max(MAGIC,(now-i)/j))ret+=(len-max(MAGIC,(now-i)/j));
			now=nxt[now+1];
			j++;
		}
	}
	return ret;
}
int main()
{
	cin>>s;
	n=s.length();
	s=' '+s;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i]-'0';
 
	long long ans=workSmall()+workBig();
	cout<<ans;
}