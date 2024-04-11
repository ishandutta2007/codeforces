#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069];

int main()
{
	long long i,u,k,w,e;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		e=(k>=13);
		u=!e*2-1;
		w=min(abs(k-25*!e),d);
		sq[i]=k+w*u;
		d-=w;
	}
	if(d)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",(char)sq[i]+'a'," \n"[i==n]);
	}
}