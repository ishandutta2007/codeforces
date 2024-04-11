#include<iostream>
#include<cstdio>
#include<string>
typedef long long ll;
using namespace std;
char a[1000001],s[1000001],ans[1000001];
ll n,minn=1ll<<60;
void cpt()
{
	for(ll i=3;i<n;i+=3)
	{
		a[i]=a[0],a[i+1]=a[1],a[i+2]=a[2];
	}
	ll cnt=0;
	
	for(ll i=0;i<n;++i)
	{
		if(a[i]!=s[i])++cnt;
	}
	if(cnt<minn)
	{
		minn=cnt;
		for(ll i=0;i<n;++i)ans[i]=a[i];
	}
}
void dfs(ll x)
{
	if(x>2)
	{
		cpt();return;
	}
	bool flag=1;
	for(ll i=0;i<x;++i)
		if(a[i]=='R')flag=0;
	if(flag)
	{
		a[x]='R';dfs(x+1);
	}
	flag=1;
	for(ll i=0;i<x;++i)
		if(a[i]=='G')flag=0;
	if(flag)
	{
		a[x]='G';dfs(x+1);
	}
	flag=1;
	for(ll i=0;i<x;++i)
		if(a[i]=='B')flag=0;
	if(flag)
	{
		a[x]='B';dfs(x+1);
	}
}
int main()
{
	cin>>n>>s;
	dfs(0);
	cout<<minn<<endl;
	for(ll i=0;i<n;++i)putchar(ans[i]);
	return 0;
}