#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e3+1e2+7;

int n,m,a[N],s;

struct node{
	int l,r;
}t[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i].l>>t[i].r;
		if(s>=t[i].l&&s<=t[i].r)
		{
			cout<<s;
			return 0;
		}
		if(t[i].l>s)
		{
			cout<<t[i].l;
			return 0;
		}
	}
	cout<<-1;
}