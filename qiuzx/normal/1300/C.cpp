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
using namespace std;
int main(){
	ll n,i,j,x,y;
	vector<ll> a;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(i=30;i>=0;i--)
	{
		x=0;
		for(j=0;j<n;j++)
		{
			if((a[j]&(1<<i))!=0)
			{
				x++;
				y=j;
			}
			if(x>1)
			{
				break;
			}
		}
		if(x==1)
		{
			cout<<a[y]<<" ";
			i=100;
			break;
		}
	}
	if(i==100)
	{
		for(i=0;i<n;i++)
		{
			if(i!=y)
			{
				cout<<a[i]<<" ";
			}
		}
	}
	else
	{
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
	}
	cout<<endl;
	return 0;
}