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
ll n,b[N],a[N];
int main(){
	ll i,mx=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		a[i]=mx+b[i];
		mx=max(mx,a[i]);
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}