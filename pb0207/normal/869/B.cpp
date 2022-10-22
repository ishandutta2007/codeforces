#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

ll a,b,ans=1;
	
int main()
{
	cin>>a>>b;
	for(ll i=a+1;i<=b;i++)
	{
		ans=(ans*i)%10;
		if(ans==0)
			break;
	}
	cout<<ans;
}