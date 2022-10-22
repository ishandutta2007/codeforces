#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

int T;

ll x;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>x;
		if(x%4==0)
			cout<<x/4;
		if(x%4==1)
		{
			if(x<9)
				cout<<"-1";
			else
				cout<<x/4-1;
		}
		if(x%4==2)
		{
			if(x<6)
				cout<<"-1";
			else
				cout<<x/4;
		}
		if(x%4==3)
		{
			if(x<15)
				cout<<"-1";
			else
				cout<<(x-9)/4+1;
		}
		cout<<endl;
	}
}