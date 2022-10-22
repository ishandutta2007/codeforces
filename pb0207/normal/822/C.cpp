#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const long long N=2e5+1e3+7;

struct node{
	long long l,r,c;
}a[N];

bool cmp(node a,node b)
{
	return a.l<b.l;
}

bool operator <(node a,node b)
{
	return a.r>b.r;
}

long long n,ans[N],x,anss;

int main()
{
	cin>>n>>x;
	for(long long i=1;i<=n;i++)
		cin>>a[i].l>>a[i].r>>a[i].c;
	sort(a+1,a+n+1,cmp);
	priority_queue<node>q;
	for(long long i=1;i<=(int)2e5+1;i++)
		ans[i]=0x7fffffff;
	anss=0x7fffffff;
	for(long long i=1;i<=n;i++)
	{
		while(q.size()&&q.top().r<a[i].l)
		{
			node k=q.top();q.pop();
			ans[k.r-k.l+1]=min(ans[k.r-k.l+1],k.c);
		}
		long long now=x-(a[i].r-a[i].l+1);
		if(now>0)
			anss=min(anss,ans[now]+a[i].c);
		q.push(a[i]);
	}
	cout<<(anss==0x7fffffff?-1:anss);
}