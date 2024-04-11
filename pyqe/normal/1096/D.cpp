#include <bits/stdc++.h>

using namespace std;

long long n,yk[26],a[100069],wg[100069],sm[4],mn[4];
string ky="hard";

int main()
{
	long long i,j;
	string s;
	
	for(i=0;i<26;i++)
	{
		yk[i]=-1;
	}
	for(i=0;i<4;i++)
	{
		yk[ky[i]-'a']=i;
	}
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=yk[s[i-1]-'a'];
		scanf("%lld",wg+i);
		if(a[i]+1)
		{
			sm[a[i]]+=wg[i];
			if(a[i])
			{
				mn[a[i]]=min(mn[a[i]],mn[a[i]-1]+sm[a[i]-1]-sm[a[i]]);
			}
		}
	}
	printf("%lld\n",mn[3]+sm[3]);
}