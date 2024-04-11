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
	ll t,n,g,b,x,nd;
	cin>>t;
	while(t--)
	{
		cin>>n>>g>>b;
		x=g+b;
		nd=(n+1)/2;
		if(nd<=g)
		{
			cout<<n<<endl;
		}
		else
		{
			nd-=g;
			if(nd%g==0)
			{
				cout<<max(n,g+nd/g*x+nd%g)<<endl;
			}
			else
			{
				cout<<max(n,g+nd/g*x+nd%g+b)<<endl;
			}
		}
	}
	return 0;
}