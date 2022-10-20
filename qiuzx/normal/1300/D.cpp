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
#define N 100010
using namespace std;
int main(){
	ll n,a[N],b[N],i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n%2==1)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(i=0;i*2<n;i++)
	{
		if(((b[i+1]-b[i])*(a[(i+n/2+1)%n]-a[i+n/2])!=(b[(i+n/2+1)%n]-b[i+n/2])*(a[i+1]-a[i]))||abs(b[i+1]-b[i])*abs(b[i+1]-b[i])+abs(a[i+1]-a[i])*abs(a[i+1]-a[i])!=abs(b[(i+n/2+1)%n]-b[i+n/2])*abs(b[(i+n/2+1)%n]-b[i+n/2])+abs(a[(i+n/2+1)%n]-a[i+n/2])*abs(a[(i+n/2+1)%n]-a[i+n/2]))
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}