#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=1e6+10;
int n,m,ans=1;
vector<pair<int,int> >e[M];

struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int k,int x)
	{
		for (int i=k;i<=1e6+2;i+=lowbit(i))
			c[i]+=x;
	}
	int ask(int x)
	{
		int res=0;
		for (int i=x;i>=1;i-=lowbit(i))
			res+=c[i];
		return res;
	}
	int query(int a,int b){return ask(b)-ask(a-1);}
}T;

/*struct BIT
{
	int c[M];
	int lowbit(int x){return x&(-x);}
	void add(int k,int x){c[k]+=x;}
	int query(int a,int b){int res=0;for (int i=a;i<=b;i++)res+=c[i];return res;}
}T;*/

struct query
{
	int x,l,r;
}q[M];

bool cmp(query a,query b){return a.x<b.x;}

int read(){int x;scanf("%lld",&x);return x;}// 

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		int a=read(),l=read(),r=read();
		e[l].push_back(make_pair(a,1));
		e[r+1].push_back(make_pair(a,-1));
		if (l==0&&r==1e6)ans++;
	}
	for (int i=1;i<=m;i++)
	{
		q[i].x=read(),q[i].l=read(),q[i].r=read();
		if (q[i].l==0&&q[i].r==1e6)ans++;
	}//cout<<ans<<endl;
	int l=0;
	sort(q+1,q+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		while(l<=q[i].x)
		{
			for (int j=0;j<e[l].size();j++)
				T.add(e[l][j].first,e[l][j].second);
			l++;
		}
		ans+=T.query(q[i].l,q[i].r);
	}cout<<ans<<endl;
	return 0;
}