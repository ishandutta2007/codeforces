#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long n,q,u,v;
unordered_map<long long,int> f;
long long p[23];
int cnt[23],ok[23];
int top=0;
void gao(long long cur,int dep)
{
//	cerr<<"gao "<<cur<<' '<<dep<<endl;
	if(dep==top+1)
	{
		for(int i=1;i<=top;i++)
		{
			if(ok[i])
				f[cur]+=f[cur/p[i]],f[cur]%=MOD;
		}
		return;
	}
	gao(cur,dep+1);
	ok[dep]=1;
	for(int i=1;i<=cnt[dep];i++)
	{
		cur*=p[dep];
		gao(cur,dep+1);
	}
	ok[dep]=0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			p[++top]=i;
			while(n%i==0)
			{
				n/=i;
				cnt[top]++;
			}
		}
	}
	if(n!=1)
	{
		p[++top]=n;
		cnt[top]++;
	}
	f[1]=1;
	gao(1,1);
	cin>>q;
	while(q--)
	{
		cin>>u>>v;
		long long g=__gcd(u,v);
		cout<<(1ll*f[u/g]*f[v/g])%MOD<<endl;
	}
	return 0;
}