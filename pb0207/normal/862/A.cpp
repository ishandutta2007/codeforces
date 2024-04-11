#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,x,a[101],vis[101];

int main()
{
	cin>>n>>x;
	int ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],vis[a[i]]++;
	for(int i=0;i<x;i++)
		ans+=(vis[i]==0);
	ans+=vis[x];
	cout<<ans;
}