#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

ll a,b,c;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		ll ans1,ans2;
		if(a>=c)
			ans1=-1;
		else
			ans1=1;
		if(a*b<=c)
			ans2=-1;
		else
			ans2=b;
		cout<<ans1<<" "<<ans2<<endl;
	}	
}