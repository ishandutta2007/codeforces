#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=(1<<12)+5;
const int M=(1<<16)+5;
const int B=1<<8;
const int U=2.2e6+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct Set
{
	int l,r,x,y;
}S[U];
int cnt=0;
int merge(int x,int y)
{
	if (!x||!y) return x|y;
	assert(S[x].r<S[y].l);
	S[++cnt]=(Set){S[x].l,S[y].r,x,y};
	assert(cnt<=2.2e6);
	return cnt;
}
struct node
{
	vector<int>p;
	vector<vector<int>>ans;
	node(){}
	node(int x)
	{
		p=vector<int>({x});
		ans=vector<vector<int>>(1,vector<int>({x}));
	}
	int ask(int l,int r)
	{
		l=lower_bound(p.begin(),p.end(),l)-p.begin();
		r=upper_bound(p.begin(),p.end(),r)-p.begin()-1;
		if (l>r) return 0;
		return ans[l][r];
	}
	friend node operator +(node a,node b)
	{
		node ret;
		for (int i:a.p) ret.p.push_back(i);
		for (int i:b.p) ret.p.push_back(i);
		sort(ret.p.begin(),ret.p.end());
		ret.ans=vector<vector<int>>(ret.p.size(),vector<int>(ret.p.size()));
		for (int i=0;i<(int)ret.p.size();i++)
		for (int j=0;j<(int)ret.p.size();j++)
		ret.ans[i][j]=merge(a.ask(ret.p[i],ret.p[j]),b.ask(ret.p[i],ret.p[j]));
		return ret;
	}
}t[N/B+5];
int p[N];
node solve(int l,int r)
{
	if (l==r) return node(p[l]);
	int mid=(l+r)/2;
	return solve(l,mid)+solve(mid+1,r);
}
int ans[M];

signed main()
{
	int n=cnt=read(),Q=read(),m=0;
	for (int i=1;i<=n;i++) p[S[i].l=S[i].r=read()]=i;
	for (int i=1;i<=n;i+=B) t[++m]=solve(i,min(i+B-1,n));
	for (int i=1;i<=Q;i++)
	{
		int l=read(),r=read();
		for (int j=1;j<=m;j++) ans[i]=merge(ans[i],t[j].ask(l,r));
	}
	print(cnt);
	for (int i=n+1;i<=cnt;i++) print(S[i].x,' '),print(S[i].y);
	for (int i=1;i<=Q;i++) print(ans[i]," \n"[i==Q]);
	
	return 0;
}