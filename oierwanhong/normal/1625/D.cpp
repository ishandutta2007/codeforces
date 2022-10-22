#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
typedef std::vector<int> P;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 300011;
int k;
struct Trie
{
	int t[MAXN*32][2],val[MAXN*32],cnt;
	void clear()
	{
		while(cnt)t[cnt][0]=t[cnt][1]=0,val[cnt]=0,--cnt;
		cnt=1;
	}
	void insert(int x)
	{
		//printf("insert %d\n",x);
		int u=1;
		for(int i=29;i>=0;--i)
		{
			bool c=x>>i&1;
			int &v=t[u][c];
			if(!v)v=++cnt;
			u=v,val[u]=x;
		}
	}
	int Query(int x)
	{
		//printf("query %d\n",x);
		int u=1;
		for(int i=29;i>=0;--i)
		{
			bool c=x>>i&1,d=k>>i&1;
			if(d)u=t[u][!c];
			else
			{
				if(t[u][!c])return val[t[u][!c]];
				u=t[u][c];
			}
			if(!u)return 0;
		}
		return val[u];
	}
}T;
std::multiset<int>res;
void solve(P a,int h)
{
	if(a.empty())return;
	if(h<0)
	{
		for(auto x:a)res.insert(x);
		return;
	}
	if(k>>h&1)
	{
		T.clear();
		for(auto x:a)
			if(x>>h&1)T.insert(x);
		for(auto x:a)
			if(!(x>>h&1)&&T.Query(x))
			{
				res.insert(x),res.insert(T.Query(x));return;
			}
		res.insert(*a.begin());
		return;
	}
	P la,ra;
	for(auto x:a)
		if(x>>h&1)ra.emplace_back(x);
		else la.emplace_back(x);
	solve(la,h-1),solve(ra,h-1);
}
int main()
{
	int n=read();
	k=read();
	P a(n);
	for(int i=0;i<n;++i)a[i]=read();
	solve(a,29);
	if(res.size()<2)
	{
		puts("-1");return 0;
	}
	printf("%d\n",int(res.size()));
	for(int i=0;i<n;++i)
		if(res.find(a[i])!=res.end())
		{
			res.erase(res.find(a[i]));
			printf("%d ",i+1);
		}
	puts("");
	return 0;
}