#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=8e5+5;

ll read()
{
	ll s=0;
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
priority_queue<ll,vector<ll>,less<ll>>q1;
priority_queue<ll,vector<ll>,greater<ll>>q2;
ll v0,d0,sum;
struct node
{
	ll p,x;
	bool operator <(const node &a)const
	{
		return p<a.p;
	}
}a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ll n=read();
	for (ll i=1;i<=n;i++)
	{
		ll x=read(),y=read();
		a[i].p=x+y;
		a[i].x=x;
	}
	sort(a+1,a+1+n);
	for (ll i=1;i<=n;i++)
	{
		sum+=a[i].p-a[i-1].p;
		v0+=a[i].x;
		d0++;
		if (q1.empty()||a[i].x<=q1.top()) q1.push(a[i].x),q1.push(a[i].x);
									 else q2.push(a[i].x-sum),q2.push(a[i].x-sum);
		if (q1.size()>q2.size()) q2.push(q1.top()-sum),q1.pop();
		if (q1.size()<q2.size()) q1.push(q2.top()+sum),q2.pop();
	}
	ll now=-d0,ans=v0,last=0;
	stack<ll>st;
	while (!q1.empty()) st.push(q1.top()),q1.pop();
	while (!st.empty())
	{
		ans+=now*(st.top()-last);
		last=st.top();
		now++;
		st.pop();
	}
	print(ans);
	
	return 0;
}