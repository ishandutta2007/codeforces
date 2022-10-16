#include <iostream>
#include <map>

using namespace std;

int main()
{
	long long n,i;
	string s;
	map <string,long long> m;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(m[s]==0)
		{
			cout<<"OK\n";
		}
		else
		{
			cout<<s<<m[s]<<endl;
		}
		m[s]++;
	}
}