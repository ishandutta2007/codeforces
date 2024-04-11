#include <iostream>

using namespace std;

int main()
{
	long long n,i,k,x=0,y=0,z=0;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		x+=k;
		cin>>k;
		y+=k;
		cin>>k;
		z+=k;
	}
	if(x==0&&y==0&&z==0)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}