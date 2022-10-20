#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool GreenDay()
{
	queue<ll>q;
	int n=read();
	map<int,int>mp; ll sum=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		sum+=x,mp[x]++;
	}
	q.push(sum);
	for (int i=1;i<n;i++)
	{
		ll x,f=1;
		do
		{
			x=q.front(),q.pop();
			if (mp.count(x)&&mp[x]) mp[x]--;
							   else f=0;
		}while (f);
		if (x==1) return 0;
		q.push(x/2),q.push(x-x/2);
	}
	while (1)
	{
		ll x=q.front();
		if (mp.count(x)&&mp[x]) mp[x]--,q.pop();
						   else break;
	}
	return q.empty();
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) puts(GreenDay()?"YES":"NO");
	
	return 0;
}