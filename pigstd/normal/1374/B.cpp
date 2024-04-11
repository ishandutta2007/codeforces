#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
	cin>>T;
	while(T--)
	{
		int a;
		int sum=0;
		cin>>a;
		while(a%6==0)
			a/=6,sum++;
		while(a%3==0)
			a/=3,sum+=2;
		if (a!=1)cout<<-1<<endl;
		else cout<<sum<<endl;
	}
	return 0;
}