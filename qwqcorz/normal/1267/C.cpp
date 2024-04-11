#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int d[N];
vector<vector<int>>ans;
struct dsu
{
	int fa[N];
	void send(int n){for (int i=1;i<=n;i++) fa[i]=i;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){fa[find(x)]=find(y);}
}ds;
set<pair<int,int>>S,Sj;
void insert(pair<int,int>x)
{
	if (x.first&1) Sj.insert(x);
	S.insert(x);
}
void erase(pair<int,int>x)
{
	if (x.first&1) Sj.erase(x);
	S.erase(x);
}

signed main()
{
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	
	int n=read(),sum=0;
	for (int i=1;i<=n;i++) sum+=d[i]=read();
	if (sum&1) return puts("-1"),0;
	if (sum/2>n-1+(n-1)/2) return puts("-1"),0;
	for (int i=1;i<=n;i++) insert(make_pair(d[i],i));
	ds.send(n);
	while (!S.empty())
	{
		int now=S.begin()->second;
		S.erase(S.begin());
		if (d[now]>2) return puts("-1"),0;
		if (d[now]==1)
		{
			if (S.empty()) return puts("-1"),0;
			int tmp=Sj.empty()||Sj.rbegin()->first<2?S.rbegin()->second:Sj.rbegin()->second;
			erase(make_pair(d[tmp],tmp));
			d[now]--,d[tmp]--;
			ds.merge(now,tmp);
			ans.push_back(vector<int>({now,tmp}));
//			print(now,' '),print(tmp);
			if (d[tmp]) insert(make_pair(d[tmp],tmp));
		}
		else
		{
			if (S.empty()) return puts("-1"),0;
			if (S.rbegin()->first==2)
			{
				if (S.size()<2) return puts("-1"),0;
				vector<int>tmp({now});
				for (auto i:S) tmp.push_back(i.second),ds.merge(i.second,now);
				tmp.push_back(now),ans.push_back(tmp);
				break;
			}
			int x=S.begin()->second;
			erase(*S.begin());
			if (S.empty()) return puts("-1"),0;
			int y=S.rbegin()->second;
			erase(*S.rbegin());
			d[now]-=2,d[x]-=2,d[y]-=2;
			ds.merge(now,x),ds.merge(x,y);
//			print(now,' '),print(x);
//			print(x,' '),print(y);
//			print(y,' '),print(now);
			ans.push_back(vector<int>({now,x,y,now}));
			if (d[y]) insert(make_pair(d[y],y));
		}
//		for (int i=1;i<=n;i++) print(d[i]," \n"[i==n]);
	}
	int tot=0;
	for (int i=1;i<=n;i++) tot+=i==ds.fa[i];
	if (tot>1) return puts("-1"),0;
	print(ans.size());
	for (auto i:ans)
	{
		print(i.size(),' ');
		for (int j:i) print(j,' ');
		puts("");
	}
	
	return 0;
}