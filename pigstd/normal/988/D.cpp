#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
int a[M],n,ans=1;
map<int,int>t;

struct Hashtable
{
	int mod=1000003;
	vector<int>v[1000003+10];
	void add(int a)
	{
		int p=a%mod;
		p+=mod,p%=mod;
		v[p].pb(a);
	}
	bool insert(int a)
	{
		int p=a%mod;
		p+=mod,p%=mod;
		for (int i=0;i<v[p].size();i++)
			if (v[p][i]==a)return 1;
		return 0;
	}
}T;

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read(),
		T.add(a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=31;j++)
		{
			if (T.insert(a[i]+(1<<j)))ans=2;
			if (T.insert(a[i]+(1<<j)))ans=2;
		}
		if (ans==2)break;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=31;j++)
		{
			if (T.insert(a[i]+(1<<j))&&T.insert(a[i]+(1ll<<(j+1))))ans=3;
			if (T.insert(a[i]-(1<<j))&&T.insert(a[i]-(1ll<<(j+1))))ans=3;
		}
		if (ans==3)break;
	}
	cout<<ans<<endl;
	if (ans==1)cout<<a[1]<<endl;
	else if (ans==2)
	{
		for (int i=1;i<=n;i++)
			for (int j=0;j<=31;j++)
				if (T.insert(a[i]+(1<<j))){cout<<a[i]<<' '<<a[i]+(1<<j)<<endl;return 0;}
				else if (T.insert(a[i]-(1<<j))){cout<<a[i]<<' '<<a[i]-(1<<j)<<endl;return 0;}
	}
	else
	{
		for (int i=1;i<=n;i++)
			for (int j=0;j<=31;j++)
				if (T.insert(a[i]+(1<<j))&&T.insert(a[i]+(1ll<<(j+1)))){cout<<a[i]<<' '<<a[i]+(1<<j)<<' '<<(a[i]+(1ll<<(j+1)));return 0;}
				else if (T.insert(a[i]-(1<<j))&&T.insert(a[i]-(1ll<<(j+1)))){cout<<a[i]<<' '<<a[i]-(1<<j)<<' '<<(a[i]-(1ll<<(j+1)));return 0;}
	}
	return 0;
}