#include<bits/stdc++.h>
#define int long long
using namespace std;

int T;
int a,b,n,m;

signed main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>n>>m;
		if (n+m>a+b)cout<<"No"<<endl;
		else if (min(a,b)<m)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}