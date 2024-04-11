#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void work()
{
	int n=read(),m=read();
	vector<pair<int,int>>A,B;
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=1;
		while (x%m==0) x/=m,y*=m;
		if (!A.empty()&&A.back().first==x) A.back().second+=y;
		else A.push_back({x,y});
	}
	n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=1;
		while (x%m==0) x/=m,y*=m;
		if (!B.empty()&&B.back().first==x) B.back().second+=y;
		else B.push_back({x,y});
	}
	puts(A==B?"Yes":"No");
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}