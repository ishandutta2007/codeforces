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
ll n,a,b,nd,ans;
int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		if(a==b&&a==1)
		{
			cout<<1<<" "<<1<<endl;
			continue; 
		}
		if(a==b&&a==n)
		{
			cout<<n<<" "<<n<<endl;
			continue;
		}
		//find min
		nd=max(a+b-n+1,(ll)1);
		cout<<nd<<" ";
		//find max
		nd=min(a+b-1,n);
		cout<<nd<<endl;
	}
	return 0;
}