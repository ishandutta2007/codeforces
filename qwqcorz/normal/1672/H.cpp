#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int B=400;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];
struct Query
{
	int l,r,id;
	bool operator <(const Query &a)const
	{
		return l/B!=a.l/B?l<a.l:r<a.r;
	}
}q[N];
int ans[N],st[N];
struct mydeque
{
	int h,t,ans=0;
	pair<int,int>q[N*2];
	void clear(){h=N,t=N-1,ans=0;}
	void addr(int x)
	{
		if (h<t&&q[t].second==x&&q[t-1].second!=x) t--;
		if (h<=t&&q[t].second!=x) q[t].second^=1;
		else ans++,q[++t]={x,x};
	}
	int m,tans;
	vector<pair<int,int>>v;
	void mark(){v.clear(),m=h-1,tans=ans;}
	void addl(int x)
	{
		if (h<t&&q[h].first==x&&q[h+1].first!=x)
		{
			if (h>m) m=h,v.push_back(q[h]);
			h++;
		}
		if (h<=t&&q[h].first!=x)
		{
			if (h>m) m=h,v.push_back(q[h]);
			q[h].first^=1;
		}
		else ans++,q[--h]={x,x};
	}
	void rollback()
	{
		ans=tans,h=m+1;
		while (!v.empty()) q[--h]=v.back(),v.pop_back();
	}
}t;

signed main()
{
	int n=read(),Q=read(),cntq=0;
	scanf("%s",a+1);
	for (int k=1;k<=Q;k++)
	{
		int l=read(),r=read();
		if (l/B==r/B)
		{
			int top=0,cnt[2]={},res=0;
			for (int i=l;i<=r;i++)
			{
				int now=a[i]-'0';
				if (!cnt[!now]) st[++top]=i,cnt[now]++,res++;
				else
				{
					if (a[st[top]]==a[i]) cnt[a[st[top--]]-'0']--;
					cnt[a[st[top]]-'0']--;
					st[top]=i,cnt[now]++;
				}
			}
			ans[k]=res;
		}
		else q[++cntq].l=l,q[cntq].r=r,q[cntq].id=k;
	}
	sort(q+1,q+1+cntq),q[0].l=-B;
	for (int i=1,l,r;i<=cntq;i++)
	{
		if (q[i-1].l/B!=q[i].l/B) t.clear(),l=q[i].l/B*B+B,r=l-1;
		while (r<q[i].r) t.addr(a[++r]-'0');
		t.mark();
		int L=l;
		while (l>q[i].l) t.addl(a[--l]-'0');
		ans[q[i].id]=t.ans;
		l=L,t.rollback();
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}