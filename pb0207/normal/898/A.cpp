#include<iostream>
using namespace std;

int n;

int main()
{
	cin>>n;
	if(n%10>5)
		n=n-n%10+10;
	else
	    n=n-n%10;
	cout<<n;
}