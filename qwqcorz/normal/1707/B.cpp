#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void work()
{
	int n=read();
	map<int,int>mp;
	for (int i=1;i<=n;i++) mp[read()]++;
	for (int i=1;i<n;i++)
	{
		vector<pair<int,int>>now;
		for (auto j:mp) now.push_back(j);
		mp.clear();
		for (int j=0;j<(int)now.size();j++) if (now[j].second>1) mp[0]+=now[j].second-1;
		for (int j=0;j+1<(int)now.size();j++) mp[now[j+1].first-now[j].first]++;
	}
	print(mp.begin()->first);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}