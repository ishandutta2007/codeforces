#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

vector<int>fac[N];
void ysgs(int n)
{
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j+=i)
	fac[j].push_back(i);
}
set<pair<int,int>>S;

signed main()
{
	ysgs(2e5);
	int n=read(),m=read();
	ll L=read(),R=read();
	for (int i=1,l=m+1,r=m;i<=n;i++)
	{
		if (R/i<(L+i-1)/i){puts("-1");continue;}
		while (l>(L+i-1)/i)
		{
			l--;
			for (int j:fac[l]) S.insert(make_pair(j,l));
		}
		while (r>R/i)
		{
			for (int j:fac[r]) S.erase(make_pair(j,r));
			r--;
		}
		bool flag=0;
		for (int a:fac[i])
		{
			auto tmp=S.lower_bound(make_pair(a,N));
			if (tmp==S.end()) break;
			auto b=*tmp;
			if (b.first<=n/(i/a))
			{
				print(i,' '),print(b.second,' '),print(i/a*b.first,' '),print(b.second/b.first*a);
				flag=1;
				break;
			}
		}
		if (!flag) puts("-1");
	}
	
	return 0;
}