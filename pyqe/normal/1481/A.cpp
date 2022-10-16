#include <bits/stdc++.h>

using namespace std;

long long n,xs,ys,yk[26],fq[4];

int main()
{
	long long t,rr,i;
	string s;
	
	yk[20]=0;
	yk[17]=1;
	yk[3]=2;
	yk[11]=3;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&xs,&ys);
		cin>>s;
		n=s.length();
		for(i=0;i<4;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			fq[yk[s[i-1]-'A']]++;
		}
		if(xs<=fq[1]&&ys<=fq[0]&&-xs<=fq[3]&&-ys<=fq[2])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}