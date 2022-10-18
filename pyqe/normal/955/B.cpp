#include <bits/stdc++.h>

using namespace std;

long long n,fq[26];

int main()
{
	long long i,k,c=0,c2=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		k=s[i]-'a';
		fq[k]++;
		c+=fq[k]==1;
		c2+=fq[k]==2;
	}
	if(c<=4&&(c>=4||(c>=3&&c2)||c2>=2))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}