#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,m,ans=1;
bool book[N],fd=false;
vector<ll> a;
int main(){
	ll i,j,x;
	cin>>n>>m;
	memset(book,0,sizeof(book));
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(book[x%m])
		{
			fd=true;
		}
		book[x%m]=true;
		a.push_back(x);
	}
	if(fd)
	{
		cout<<0<<endl;
		return 0;
	}
	for(i=0;i<a.size();i++)
	{
		for(j=i+1;j<a.size();j++)
		{
			ans=(ans*abs(a[j]-a[i]))%m;
		}
	}
	cout<<ans<<endl;
	return 0;
}