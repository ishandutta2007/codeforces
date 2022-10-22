#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

long long n,f;

long long k[N],l[N],ans;

struct node{
	long long v1,v2;
}o[N];

bool cmp(node a,node b)
{
	return a.v1>b.v1||(a.v1==b.v1&&a.v2<b.v2);
}

int main()
{
	cin>>n>>f;
	for(int i=1;i<=n;i++)
		cin>>k[i]>>l[i],o[i].v1=min(2*k[i],l[i])-min(k[i],l[i]),o[i].v2=min(k[i],l[i]);
	sort(o+1,o+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(i<=f)
			ans+=o[i].v1+o[i].v2;
		else
			ans+=o[i].v2;
	cout<<ans;
}