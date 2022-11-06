#include<bits/stdc++.h>
using namespace std;
#define int long long
struct ppl
{
	int id;
	long long t;
	inline bool operator<(const ppl &rhs)const
	{
		return t<rhs.t;
	}
}p[111111];
queue<int> q;
queue<pair<long long,int> >qq;
priority_queue<int,vector<int>,greater<int> > pq,event;
int top=1;
long long tt[111111];
int vis[111111];
long long ans[111111];
int BIT[111111];
int n;
inline void change(int pos,int d)
{
	for(int x=pos;x<=n;x+=x&-x)
	{
		BIT[x]+=d;
	}
}
inline int query(int pos)
{
	int ret=0;
	for(int x=pos;x;x-=x&-x)
	{
		ret+=BIT[x];
	}
	return ret;
}
signed main()
{
	int t;
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i].t);
		tt[i]=p[i].t;
		event.push(p[i].t);
		p[i].id=i;
	}
	sort(p+1,p+n+1);
	long long last=0;
	while(!event.empty())
	{
		int ok=1;
		long long T=event.top();event.pop();
		while(ok)
		{
			ok=0;
//			cerr<<"gao "<<top<<' '<<T<<endl;
			while(top<=n&&p[top].t<=T)
			{
//				cerr<<"push1 "<<p[top].id<<endl;
				pq.push(p[top++].id);
			}
			while(!qq.empty()&&qq.front().first<=T)
			{
				change(qq.front().second,-1);
				qq.pop();
			}
			if(!pq.empty()&&query(pq.top())==0)
			{
				ok=1;
				int x=pq.top();pq.pop();
//				cerr<<"push2 "<<x<<' '<<last<<endl;
				change(x,1);
				q.push(x);
			}
			if(!q.empty()&&max(last,tt[q.front()])<=T)
			{
				ok=1;
				int x=q.front();q.pop();
//				cerr<<"pop "<<x<<endl;
				last=max(last,tt[x]);
				last+=t;
				event.push(last);
				qq.push(make_pair(last,x));
				ans[x]=last;
			}
	/*		for(int i=1;i<=n;i++)
			{
				printf("%lld ",ans[i]);
			}
	*/
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}