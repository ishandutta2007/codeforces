#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs=0;
bitset<26> spc;
string ky="aeiouy";

int main()
{
	long long i,k;
	string s;
	
	for(i=0;i<6;i++)
	{
		spc[ky[i]-'a']=1;
	}
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		if(!(spc[k]&&zs&&spc[sq[zs]]))
		{
			zs++;
			sq[zs]=k;
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%c",(char)sq[i]+'a');
	}
	printf("\n");
}