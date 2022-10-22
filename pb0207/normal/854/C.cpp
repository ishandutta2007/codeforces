#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=3e5+1e3+7;

typedef long long ll;

ll n,k,c[N],ans,t[N];

struct node{
	ll c,v;
}a[N];

bool operator <(node x,node y)
{
	return x.c<y.c;
}

priority_queue<node>q;

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i].c),a[i].v=i;
		if(i<=k)
			q.push(a[i]);
	}
	for(int i=k+1;i<=k+n;i++)
	{
		if(i<=n)
			q.push(a[i]);
		node now=q.top();
		q.pop();
		t[now.v]=i;
		ans+=now.c*(i-now.v);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		printf("%I64d ",t[i]);
}