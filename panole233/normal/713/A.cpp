#include<bits/stdc++.h>
using namespace std;

long long x;
int t[1<<20|3],q,o[21],oN;
char s[5];

int calc(long long x)
{
	oN=0;
	while (x) o[++oN]=x%10,x/=10;
	int ans=0;
	for (int i=oN; i; i--) ans=ans*2+(o[i]&1);
	return ans;
}

int main()
{
	scanf("%d",&q);
	memset(t,0,sizeof(t));
	while (q--)
	{
		scanf("%s%I64d",s,&x),x=calc(x);
		if (s[0]=='+') t[x]++; else
		if (s[0]=='-') t[x]--; else printf("%d\n",t[x]);
	}
	return 0;
}