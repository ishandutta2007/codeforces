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
#define N 1010
using namespace std;
ll n,m[N],ans[N],t[N],sum,tp=0;
int main(){
	ll i,j,mx;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m[i];
	}
	for(i=0;i<n;i++)
	{
		sum=m[i];
		t[i]=m[i];
		mx=m[i];
		for(j=i-1;j>=0;j--)
		{
			t[j]=min(m[j],mx);
			mx=min(mx,t[j]);
			sum+=t[j];
		}
		mx=m[i];
		for(j=i+1;j<n;j++)
		{
			t[j]=min(m[j],mx);
			mx=min(mx,t[j]);
			sum+=t[j];
		}
		if(tp<sum)
		{
			tp=sum;
			for(j=0;j<n;j++)
			{
				ans[j]=t[j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}