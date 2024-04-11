#include <iostream>

using namespace std;

int main()
{
	long long n,i,c=0;
	string s;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(s=="X++"||s=="++X")
		{
			c++;
		}
		if(s=="X--"||s=="--X")
		{
			c--;
		}
	}
	cout<<c<<endl;
}