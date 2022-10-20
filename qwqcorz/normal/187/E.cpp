#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const ll inf=1LL<<60;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct albcwt
{
	priority_queue<int,vector<int>,less<int>>q1;
	priority_queue<int,vector<int>,greater<int>>q2;
	int k;
	ll sum;
	void fix()
	{
		while (!q1.empty()&&!q2.empty()&&q1.top()>q2.top()) sum+=q2.top(),q1.push(q2.top()),q2.pop();
		while (!q2.empty()&&(int)q1.size()<k) sum+=q2.top(),q1.push(q2.top()),q2.pop();
		while (!q1.empty()&&(int)q1.size()>k) sum-=q1.top(),q2.push(q1.top()),q1.pop();
	}
	void set(int _k){k=_k,fix();}
	void add(int x){q2.push(x),fix();}
	void clear()
	{
		sum=k=0;
		while (!q1.empty()) q1.pop();
		while (!q2.empty()) q2.pop();
	}
}t;
bool is[N];
int a[N],n,k,s,id[N],x[N],tmp[N];
pair<ll,vector<int>>solve(int n,int k,int s)
{
	if (k==0&&s>1) return make_pair(inf,vector<int>{});
	int ans=(a[s]-a[1])*2,now=s;
	vector<int>p;
	for (int i=1;i<s&&k>1;i++)
	{
		k--;
		p.push_back(--now);
	}
	k-=now>1;
	for (int i=1;i<now;i++) p.push_back(i);
	if (s==n) return make_pair(ans,p);
	////////////////////////////////////////////////////////
	ans+=a[n]-a[s];
	if (k==0)
	{
		for (int i=s+1;i<=n;i++) p.push_back(i);
		return make_pair(ans,p);
	}
	t.clear();
	int m=-1;
	for (int i=s+1;i<=n;i++) x[++m]=a[i]-a[i-1],id[m]=i;
	for (int i=1;i<=m-k;i++) t.add(x[i]);
	ll sum=0;
	pair<ll,int>mn(inf,0);
	for (int i=m;i>m-k;i--) sum+=x[i];
	for (int i=k;i>=0;i--)
	{
		t.set(k-i);
		mn=min(mn,make_pair(t.sum*2+sum,i));
		if (i==0) break;
		sum-=x[m-i+1];
		t.add(x[m-i+1]);
	}
	////////////////////////////////////////////////////////
	int zyk=mn.second;
	for (int i=1;i<=m-zyk;i++) tmp[i]=i;
	sort(tmp+1,tmp+1+m-zyk,[&](int u,int v){return x[u]<x[v];});
	memset(is,1,sizeof(is));
	for (int i=1;i<=k-zyk;i++) is[tmp[i]-1]=0;
	for (int i=1;i<=zyk;i++) is[m-i]=0;
	stack<int>st;
	for (int i=0;i<=m;i++)
	if (is[i])
	{
		p.push_back(id[i]);
		while (!st.empty()) p.push_back(st.top()),st.pop();
	}
	else st.push(id[i]);
	return make_pair(ans+mn.first,p);
}
pair<ll,vector<int>>solve1(){return solve(n,k,s);}
pair<ll,vector<int>>solve2()
{
	for (int i=1;i<=n;i++) a[i]=-a[i];
	reverse(a+1,a+1+n);
	auto ret=solve(n,n-1-k,n+1-s);
	for (int &i:ret.second) i=n+1-i;
	return ret;
}

signed main()
{
	n=read(),k=read(),s=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (k>n-1-(s<n)) return puts("-1"),0;
	if (k==0&&s>1) return puts("-1"),0;
	auto ans=solve1();
	ans=min(ans,solve2());
	print(ans.first);
	for (int i:ans.second) print(i,' ');
	
	return 0;
}