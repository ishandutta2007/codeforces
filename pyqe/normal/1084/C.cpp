#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long sz;
vector <long long> v;

int main()
{
	long long i,ln,k=0,z=1,inmx=1000000007;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<=ln;i++)
	{
		if(k>0&&(i==ln||s[i]=='b'))
		{
			v.push_back(k%inmx);
			k=0;
		}
		else if(s[i]=='a')
		{
			k++;
		}
	}
	sz=v.size();
	for(i=0;i<sz;i++)
	{
		z*=v[i]+1;
		z%=inmx;
	}
	z--;
	if(z==-1)
	{
		z=inmx-1;
	}
	cout<<z<<endl;
}