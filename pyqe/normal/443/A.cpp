#include <iostream>
#include <map>

using namespace std;

int main()
{
	char k,c;
	long long z=0;
	map <char,bool> m;
	
	cin>>k;
	while(k!='}')
	{
		cin>>c;
		if(c=='}')
		{
			break;
		}
		if(m[c]==0)
		{
			m[c]=true;
			z++;
		}
		cin>>k;
	}
	cout<<z<<endl;
}