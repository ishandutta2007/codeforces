#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,l,r,a[N],b[N],last;

struct node{
	int v,id;
}c[N];

bool cmp(node a,node b)
{
	return a.v<b.v;
}

int main()
{
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>c[i].v,c[i].id=i;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int k=c[i].id;
		if(i==1)
		{
			b[k]=l;
			last=b[k]-a[k];
			continue;
		}
		if(l-a[k]>last)
			b[k]=l;
		else
			b[k]=a[k]+last+1;
		if(b[k]>r)
		{
			cout<<"-1";
			return 0;
		}
		last=b[k]-a[k];
	}
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
}