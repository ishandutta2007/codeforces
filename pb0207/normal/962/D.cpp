#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

struct node{
	ll w,p;
	node(ll _w=0,int _p=0){w=_w,p=_p;}
};

bool operator <(node a,node b)
{
	return a.w>b.w||(a.w==b.w&&a.p>b.p);
}

priority_queue<node>q;

int n;

ll a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		q.push(node(a[i],i));
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		if(q.empty())
			break;
		node y=q.top();
		q.pop();
		if(x.w!=y.w)
		{
			q.push(y);
			continue; 
		} 
		a[x.p]=0;
		a[y.p]=2ll*y.w;
		q.push(node(2*y.w,y.p));
	}
	int tot=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
			tot++;
	cout<<tot<<endl;
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
			printf("%lld ",a[i]);
}