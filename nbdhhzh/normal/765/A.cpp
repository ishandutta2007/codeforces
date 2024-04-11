#include<bits/stdc++.h> 
using namespace std;
int n,t,p,q;
char s[1010];
int main()
{
	scanf("%d%s",&n,s);
	t=s[0]<<16|s[1]<<8|s[2];
	while(n--)
	{
		scanf("%s",s);
		p=s[0]<<16|s[1]<<8|s[2];
		if(p==t)q++;
		p=s[5]<<16|s[6]<<8|s[7];
		if(p==t)q--;
	}
	if(q==0)puts("home");else puts("contest");
}