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
ll n,m;
int main(){
	ll t,i,x;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		x=(n-m)/(m+(ll)1);
		cout<<n*(n+(ll)1)/(ll)2-(m+(ll)1-(n-m-(m+(ll)1)*x))*x*(x+(ll)1)/(ll)2-(n-m-(m+(ll)1)*x)*(x+(ll)1)*(x+(ll)2)/(ll)2<<endl;
	}
	return 0;
}