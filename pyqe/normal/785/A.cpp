#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,r,z=0;
	string s;
	
	scanf("%lld",&n);
	for(r=0;r<n;r++)
	{
		cin>>s;
		if(s=="Tetrahedron")
		{
			z+=4;
		}
		else if(s=="Cube")
		{
			z+=6;
		}
		else if(s=="Octahedron")
		{
			z+=8;
		}
		else if(s=="Dodecahedron")
		{
			z+=12;
		}
		else if(s=="Icosahedron")
		{
			z+=20;
		}
	}
	printf("%lld\n",z);
}