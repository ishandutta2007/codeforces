//copyright qiuzx
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 300000
using namespace std;
ll n,m,fan=1,ans,fat[N];
int main(){
	ll i;
	cin>>n>>m;
	fat[0]=1;
	for(i=1;i<=n;i++)
	{
		fan=(fan*i)%m;
		fat[i]=fan;
	}
	if(n==1)
	{
		cout<<1<<endl;
		return 0;
	}
	else if(n==2)
	{
		cout<<6<<endl;
		return 0;
	}
	ans=(fat[n]*n)%m;
	for(i=1;i<n;i++)
	{
		//cout<<ans<<endl;
		ans=(ans+((((((n-i)*(n-i))%m*(i+1))%m*i)%m*fat[i-1])%m*fat[n-i-1])%m)%m;
	}
	cout<<ans<<endl;
	return 0;
}