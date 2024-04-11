#include <iostream>

using namespace std;

int main()
{
	long long n,i;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"I ";
		if(i%2==0)
		{
			cout<<"hate ";
		}
		else
		{
			cout<<"love ";
		}
		if(i==n-1)
		{
			cout<<"it\n";
		}
		else
		{
			cout<<"that ";
		}
	}
}