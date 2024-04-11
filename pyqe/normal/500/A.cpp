#include <iostream>

using namespace std;

int main()
{
	long long n,t,i,k,p=0;
	
	cin>>n>>t;
	for(i=0;i<n-1;i++)
	{
		cin>>k;
		if(p==i)
		{
			p+=k;
			if(t-1==p)
			{
				cout<<"YES\n";
				return 0;
			}
			else if(t-1<p)
			{
				cout<<"NO\n";
				return 0;
			}
		}
	}
}