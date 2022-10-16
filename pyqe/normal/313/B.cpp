#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,ln,c=0,n,l,r;
	string s;
	
	cin>>s;
	ln=s.length();
	long long a[ln];
	a[0]=0;
	for(i=1;i<ln;i++)
	{
		if(s[i]==s[i-1])
		{
			c++;
		}
		a[i]=c;
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",a[r-1]-a[l-1]);
	}
}