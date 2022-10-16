#include <bits/stdc++.h>

using namespace std;

long long n,a[2][300069],nn[2],p[2];

int main()
{
	long long t,rr,i,k;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		nn[0]=0;
		nn[1]=0;
		for(i=0;i<n;i++)
		{
			k=s[i]-'0';
			a[k%2][nn[k%2]]=k;
			nn[k%2]++;
		}
		for(p[0]=0,p[1]=0;p[0]<nn[0]||p[1]<nn[1];)
		{
			if(p[1]==nn[1]||(p[0]<nn[0]&&a[0][p[0]]<a[1][p[1]]))
			{
				printf("%lld",a[0][p[0]]);
				p[0]++;
			}
			else
			{
				printf("%lld",a[1][p[1]]);
				p[1]++;
			}
		}
		printf("\n");
	}
}