#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int N=1e3+1e2+7;

int n,b[N];

struct node{
	int w,id;
}a[N];

bool cmp(node a,node b)
{
	return a.w<b.w;
}

bool cc(node a,node b)
{
	return a.id<b.id;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].w,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	int tmp=a[1].w;
	for(int i=1;i<=n;i++)
		a[i].w=a[i+1].w;
	a[n].w=tmp;
	sort(a+1,a+n+1,cc);
	for(int i=1;i<=n;i++)
		cout<<a[i].w<<" ";
}