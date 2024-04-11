#include<cstdio>
#include<iostream>
using namespace std;

int sx,sy,tx,ty,a,b;

int main()
{
	cin>>sx>>sy>>tx>>ty>>a>>b;
	if((tx-sx)%a)
	{
		cout<<"NO";
		return 0;
	}
	if((ty-sy)%b)
	{
		cout<<"NO";
		return 0;
	}
	if(((tx-sx)/a+(ty-sy)/b)%2)
	{
		cout<<"NO";
	}
	else
		cout<<"YES";	
}