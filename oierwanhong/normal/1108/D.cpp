#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
char a[2000010];
ll n,ans;
char c;
int main()
{
	cin>>n;
	getchar();
	for(ll i=1;i<=n;++i)a[i]=getchar();
	for(ll i=2;i<=n;++i)
	{
		if(a[i]!=a[i-1])continue;
		++ans;
		if(a[i-1]!='R'&&a[i+1]!='R')
		{
			a[i]='R';
			continue;
		}
		if(a[i-1]!='G'&&a[i+1]!='G')
		{
			a[i]='G';
			continue;
		}
		if(a[i-1]!='B'&&a[i+1]!='B')
		{
			a[i]='B';
			continue;
		}
	}
	cout<<ans<<endl;
	for(ll i=1;i<=n;++i)putchar(a[i]);
	return 0;
}