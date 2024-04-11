#include <bits/stdc++.h>

using namespace std;

long long n;
string as[6]={"blue","green","orange","purple","red","yellow"},sq[6]={"Space","Time","Soul","Power","Reality","Mind"};
bitset<6> vtd;

int main()
{
	long long i;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		vtd[lower_bound(as,as+6,s)-as]=1;
	}
	printf("%lld\n",6-n);
	for(i=0;i<6;i++)
	{
		if(!vtd[i])
		{
			printf("%s\n",sq[i].c_str());
		}
	}
}