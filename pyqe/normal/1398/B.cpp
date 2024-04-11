#include <bits/stdc++.h>

using namespace std;

long long n,a[169];

int main()
{
	long long t,rr,i,k,ln,c,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		ln=s.length();
		c=0;
		n=0;
		for(i=0;i<ln;i++)
		{
			k=s[i]-'0';
			c+=k;
			if(k&&(i==ln-1||s[i+1]=='0'))
			{
				n++;
				a[n]=c;
				c=0;
			}
		}
		sort(a+1,a+n+1,greater<long long>());
		z=0;
		for(i=1;i<=n;i+=2)
		{
			z+=a[i];
		}
		printf("%lld\n",z);
	}
}