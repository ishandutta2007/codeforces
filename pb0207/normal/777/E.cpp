#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=1e5+10;

struct node
{
	int a,b,h;
}q[maxn];

int cmp(node x,node y)
{
	if(x.b==y.b)
	return x.a>y.a;
	else
	return x.b>y.b;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].h);
	}
	sort(q,q+n,cmp);
	stack<node>s;
	while(!s.empty())
		s.pop();
	s.push(q[0]);
	ll sum=q[0].h,ans=q[0].h;
	for(int i=1;i<n;i++)
	{
		while(!s.empty()&&q[i].b<=s.top().a)
		{
			sum-=s.top().h;
			s.pop();
		}
		sum+=q[i].h;
		ans=max(ans,sum);
		s.push(q[i]);
	}
	printf("%I64d\n",ans);
	return 0;
}