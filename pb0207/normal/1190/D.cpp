#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int n;

struct node{
	int x,y;
}a[N];

int px[N];

map<int,int>S;

bool cmp(node a,node b)
{
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}

ll ans;

int c[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int v)
{
	while(x<=n)
	{
		c[x]+=v;
		x+=lowbit(x);
	}
}

int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=lowbit(x);
	} 
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		px[i]=a[i].x;
	sort(px+1,px+n+1);
	for(int i=1;i<=n;i++)
		a[i].x=lower_bound(px+1,px+n+1,a[i].x)-px;
	for(int i=1;i<=n;i++)
		px[i]=a[i].y;
	sort(px+1,px+n+1);
	for(int i=1;i<=n;i++)
		a[i].y=lower_bound(px+1,px+n+1,a[i].y)-px;
	sort(a+1,a+n+1,cmp);
	int last;
	for(int i=n;i>=1;i=last-1)
	{
		last=i;
		while(last>1&&a[last-1].y==a[last].y)
			last--;
		for(int j=last;j<=i;j++)
			if(!S[a[j].x])
				S[a[j].x]++,add(a[j].x,1);
		ans+=1ll*query(a[i].x)*(query(n)-query(a[i].x-1));
		for(int j=last;j<i;j++)
			ans+=1ll*query(a[j].x)*(query(a[j+1].x-1)-query(a[j].x-1));
	}
	printf("%lld",ans);
}