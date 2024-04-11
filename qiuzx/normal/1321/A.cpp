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
#define N 110
using namespace std;
ll n,a[N],b[N];
int main(){
	ll i,an=0,bn=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==1&&b[i]==0)
		{
			an++;
		}
		else if(a[i]==0&&b[i]==1)
		{
			bn++;
		}
	}
	if(an==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<(bn+an)/an<<endl;
	}
	return 0;
}