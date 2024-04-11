#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,ln,b=1,p=-1,z;
	map<char,bool> ky;
	string s;
	
	ky['A']=true;
	ky['I']=true;
	ky['U']=true;
	ky['E']=true;
	ky['O']=true;
	ky['Y']=true;
	cin>>s;
	ln=s.length();
	for(i=0;i<=ln;i++)
	{
		if(i==ln||ky[s[i]])
		{
			z=i-p;
			b=max(b,z);
			p=i;
		}
	}
	printf("%lld\n",b);
}