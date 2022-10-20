#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;

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
int a[N],n,Q,k;
struct Query
{
	int l,len,id;
};
ll ans[N];
vector<int>s[N],g[N];
vector<Query>q[N];
void ysgs(int n)
{
	static int q[N],h=1,t=0;
	for (int i=0;i<n;i++)
	{
		while (h<=t&&a[q[t]]>=a[i]) t--;
		q[++t]=i;
		if (q[h]<=i-k) h++;
		s[i%k].push_back(a[q[h]]);
		g[i%k].push_back(a[i]);
	}
}
void solve(vector<int>&a,vector<int>&b,vector<Query>&c)
{
	int top=0;
	static int st[N];
	static ll sum[N];
	int n=st[0]=a.size();
	a.push_back(0);
	vector<vector<pair<int,int>>>q(n);
	for (auto i:c) q[i.l].push_back(make_pair(i.len,i.id));
	for (int i=n-1;i>=0;i--)
	{
		int pos=lower_bound(st+1,st+top+1,b[i],[&](int x,int y){return a[x]<y;})-st-1;
		for (auto j:q[i])
		{
			int len=j.first;
			ans[j.second]=1LL*b[i]*min(len+1,st[pos]-i);
			if (i+len>=st[pos])
			{
				int tmp=lower_bound(st,st+top+1,i+len,[&](int x,int y){return x>y;})-st;
				ans[j.second]+=sum[pos]-sum[tmp];
				ans[j.second]+=1LL*a[st[tmp]]*(i+len-st[tmp]+1);
			}
		}
		while (top&&a[st[top]]>=a[i]) top--;
		st[++top]=i;
		sum[top]=1LL*(st[top-1]-i)*a[i]+sum[top-1];
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),Q=read(),k=read();
	for (int i=0;i<n;i++) a[i]=read();
	ysgs(n);
	for (int i=0;i<Q;i++)
	{
		int l=read()-1,r=read()-1;
		q[l%k].push_back((Query){l/k,(r-l)/k,i});
	}
	for (int i=0;i<k;i++) solve(s[i],g[i],q[i]);
	for (int i=0;i<Q;i++) print(ans[i]);
	
	return 0;
}