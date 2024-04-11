#include <iostream>

using namespace std;

int main()
{
	int ln[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
	long long n,i;
	
	cin>>n;
	for(i=0;ln[i]<=n;i++)
	{
		if(n%ln[i]==0)
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
}