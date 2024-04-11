#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const long double pi=acos(-1.0L);

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

map<long double,vector<long double>>mp;
int x[N],y[N];

void GreenDay()
{
	int n=read(),ans=0,sum=0;
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	{
		long double b=y[i]==y[j]?y[i]:1.0L*(x[i]*(y[j]-y[i])-y[i]*(x[j]-x[i]))/(y[j]-y[i]);
		long double k=y[i]==y[j]?1e4+5:1.0L*(x[j]-x[i])/(y[j]-y[i]);
		mp[k].push_back(b);
	}
	for (auto i:mp)
	{
		auto &a=i.second;
		sort(a.begin(),a.end());
		a.resize(unique(a.begin(),a.end())-a.begin());
		int x=a.size();
		sum+=x;
		ans+=1LL*x*(x-1)/2;
	}
	print(1LL*sum*(sum-1)/2-ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();

	return 0;
}