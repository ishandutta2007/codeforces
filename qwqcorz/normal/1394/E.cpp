#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

unordered_set<int>mp[N];
vector<int>l[N],r[N];
int a[N],b[N],cnt=0;
unordered_map<int,int>dp[N];
void del(int x)
{
	while (x--)
	{
		for (int i:l[cnt]) r[cnt-i+1].pop_back();
		dp[cnt].clear();
		mp[cnt].clear();
		l[cnt].clear();
		cnt--;
	}
}
int dfs(int L,int R)
{
	if (dp[R].count(L)) return dp[R][L];
	int &now=dp[R][L];
	for (int i:l[R])
	{
		if (R-L>=i/2) now=max(now,1+dfs(L,R-i/2));
		break;
	}
	for (int i:r[L])
	{
		if (R-L>=i/2) now=max(now,1+dfs(L+i/2,R));
		break;
	}
	return now;
}

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int now=1;now<=n;now++)
	{
		int i=++cnt;
		b[i]=a[now];
		if (b[i]==b[i-1]) l[i].push_back(2),r[i-1].push_back(2),mp[i].insert(2);
		for (int j:l[i-1]) if (b[i]==b[i-j-1]) l[i].push_back(j+2),r[i-j-1].push_back(j+2),mp[i].insert(j+2);
		for (int j:l[i])
		if (mp[i-j/2].count(j))
		{
			i-=j;
			ans+=2;
			del(j);
			break;
		}
		print(ans+dfs(1,i)," \n"[now==n]);
	}
	
	return 0;
}