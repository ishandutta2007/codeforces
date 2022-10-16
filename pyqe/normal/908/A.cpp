#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<256> spc;

int main()
{
	long long i,z=0;
	string s;
	
	spc['a']=1;
	spc['e']=1;
	spc['i']=1;
	spc['o']=1;
	spc['u']=1;
	spc['1']=1;
	spc['3']=1;
	spc['5']=1;
	spc['7']=1;
	spc['9']=1;
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		z+=spc[s[i-1]];
	}
	printf("%lld\n",z);
}