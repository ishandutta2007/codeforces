#include<cstdio>
#include<iostream>

using namespace std;

typedef long long ll;

const int N = 1e5+1e3+7;

int main()
{
	ll l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	for(ll b=x;b<=y;++b)
	if(l<=b*k&&b*k<=r)
	{
		cout<<"yes";
		return 0;
	}
	cout<<"no";
}