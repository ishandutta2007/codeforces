#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int power(int a,int b)
{
	int ret=1;
	while (b--) ret*=a;
	return ret;
}
vector<int>p;
bool vis[N];
int Q(int x)
{
	cout<<"? "<<x<<endl;
	return read();
}
void answer(int x){cout<<"! "<<x<<endl;}
void work()
{
	int ans=2;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for (int i:p) q.push({i,1});
	for (int t=22;t--;)
	{
		int k=1;
		vector<pair<int,int>>a;
		while (!q.empty())
		{
			auto [p,b]=q.top();
			int now=power(p,b);
			if (k<=1e18/now) a.push_back({p,b}),k*=now,q.pop();
						else break;
		}
		int now=Q(k);
		for (auto [p,b]:a)
		if (now%power(p,b)==0) q.push({p,b+1}),ans=ans/b*(b+1);
	}
	answer(ans);
}

signed main()
{
	for (int i=2;i<N;i++) if (!vis[i])
	for (int j=i+i;j<N;j+=i) vis[j]=1;
	for (int i=2;i<N;i++) if (!vis[i]) p.push_back(i);
	int T=read();
	while (T--) work();
	
	return 0;
}