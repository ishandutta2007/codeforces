//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 650010
using namespace std;
ll n,sq,fp[N],g[N],ans=0;
bool isprm[N];
vector<ll> allp;
ll getid(ll x){return (x<=320000)?x:(320001+n/x);}
int main(){
	ll i,j;
	allp.push_back(1);
	memset(isprm,true,sizeof(isprm));
	isprm[0]=isprm[1]=false;
	for(i=2;i<N;i++)
	{
		if(isprm[i])
		{
			allp.push_back(i);
			for(j=i+i;j<N;j+=i)
			{
				isprm[j]=false;
			}
		}
	}
	cin>>n;
	sq=sqrt(n)+2;
	vector<ll> allv;
	for(i=1;i<=n;i=n/(n/i)+1)
	{
		allv.push_back(n/i);
	}
	for(i=0;i<allv.size();i++)
	{
		g[getid(allv[i])]=allv[i]-1;
	}
	for(i=1;i<=sq&&i<allp.size();i++)
	{
		for(j=0;j<allv.size()&&allv[j]>=allp[i]*allp[i];j++)
		{
			g[getid(allv[j])]-=(g[getid(allv[j]/allp[i])]-g[getid(allp[i-1])]);
		}
	}
	for(i=1;i<allp.size()&&allp[i]*allp[i]<=n;i++)
	{
		if(allp[i]*allp[i]*allp[i]<=n)
		{
			ans++;
		}
		ans+=g[getid(n/allp[i])]-i;
	}
	cout<<ans<<endl;
	return 0;
}