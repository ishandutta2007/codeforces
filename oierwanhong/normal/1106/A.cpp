#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
char a[1001][1001];
ll n,ans=0;
int main()
{
	std::cin>>n;
	for(ll i=1;i<=n;++i)
	{
		char c;
		do
		{
			c=getchar();
		}while(c!='.'&&c!='X');
		a[i][1]=c;
		for(ll j=2;j<=n;++j)a[i][j]=getchar();
	}
	for(ll i=2;i<n;++i)
	{
		for(ll j=2;j<n;++j)
		{
			if(a[i][j]=='X'&&a[i-1][j-1]=='X'&&a[i-1][j+1]=='X'&&a[i+1][j-1]=='X'&&a[i+1][j+1]=='X')
				++ans;
		}
	}
	std::cout<<ans;
	return 0;
}