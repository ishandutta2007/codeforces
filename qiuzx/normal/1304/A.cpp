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
ll t,x,y,a,b; 
int main(){
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>a>>b;
		if((y-x)%(a+b)!=0)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<(y-x)/(a+b)<<endl;
		}
	}
	return 0;
}