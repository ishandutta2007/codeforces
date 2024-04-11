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
#define N 210
using namespace std;
ll n,m,k;
string ans="";
int main(){
	ll i,j,l,x,y;
	cin>>n>>m>>k;
	for(i=0;i<k;i++)
	{
		cin>>x>>y;
	}
	for(i=0;i<k;i++)
	{
		cin>>x>>y;
	}
	for(i=1;i<m;i++)
	{
		ans+='R';
	}
	for(i=1;i<n;i++)
	{
		ans+='D';
	}
	for(i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<m;j++)
			{
				ans+='L';
			}
		}
		else
		{
			for(j=1;j<m;j++)
			{
				ans+='R';
			}
		}
		ans+='U';
	}
	cout<<ans.size()<<endl<<ans<<endl;
	return 0;
}