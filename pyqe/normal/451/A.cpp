#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long m,n;
	
	cin>>m>>n;
	if(min(m,n)%2==0)
	{
		cout<<"Malvika\n";
	}
	else
	{
		cout<<"Akshat\n";
	}
}