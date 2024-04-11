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
using namespace std;
ll t,n;
int main(){
	ll i,s1,s2;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s1=s2=0;
		for(i=1;i<n/2;i++)
		{
			s1+=(1<<i);
		}
		for(i=n/2;i<n;i++)
		{
			s2+=(1<<i);
		}
		s1+=(1<<n);
		cout<<abs(s1-s2)<<endl;
	}
	return 0;
}