#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=3e5+1e3+7,P=1e9+7;

typedef long long ll;

ll n,x[N],s[N],mi[N],ans;

ll S(ll l,ll r)
{
	return (s[r]-s[l-1]+P)%P;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	mi[0]=1;
	for(int i=1;i<=n;i++)
		mi[i]=(mi[i-1]<<1)%P;
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
		s[i]=(s[i-1]+x[i])%P;
	for(int i=1;i<=n;i++)
		ans=(ans+(-S(1,i)+S(n-i+1,n)+P)*mi[i-1]%P)%P;
	cout<<ans;
}