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
int main(){
	ll t,x,y,a,b;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>a>>b;
		if(a*2<=b)
		{
			cout<<(x+y)*a<<endl;
		}
		else
		{
			cout<<(max(x,y)-min(x,y))*a+min(x,y)*b<<endl;
		}
	}
	return 0;
}