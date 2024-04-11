#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void up(int &x,int y){if (x<y) x=y;}
void GreenDay()
{
	map<int,int>dp;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (i==1) up(dp[x-1],0);
		for (auto now=prev(dp.end()),nxt=now;now->first>=x;now=nxt)
		{
//			print(now->first,' '),print(now->second);
			up(dp[now->first%x],now->second+(i-1)*(now->first-now->first%x));
			if (x>1) up(dp[x-1],now->second+(i-1)*((now->first+1)/x*x-1-(x-1)));
			nxt=prev(now);
			dp.erase(now);
		}
//		for (auto i:dp) print(i.first,':'),print(i.second);
//		puts("");
	}
	int ans=0;
	for (auto i:dp) ans=max(ans,i.first*n+i.second);
	print(ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}