#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];
bitset<100069> ng,spc;

int main()
{
	long long i,j,ln,sm[2]={0,0};
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		ln=s.length();
		if(s[0]=='-')
		{
			ng[i]=1;
		}
		for(j=ng[i];s[j]!='.';j++)
		{
			a[i]=a[i]*10+(s[j]-'0');
		}
		if(s.substr(j+1,5)=="00000")
		{
			spc[i]=1;
		}
		sm[ng[i]]+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(!spc[i]&&sm[ng[i]]<sm[!ng[i]])
		{
			a[i]++;
			sm[ng[i]]++;
		}
		if(ng[i]&&a[i])
		{
			printf("-");
		}
		printf("%lld\n",a[i]);
	}
}