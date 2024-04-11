#include<bits/stdc++.h>
using namespace std;

char s[500010],t[500010];
int nxt[500011],cnt[2],n;

void work()
{
	for (int i=1; i<=cnt[0]; i++) putchar('0');
	for (int i=1; i<=cnt[1]; i++) putchar('1');
	puts(""),exit(0);
}

int main()
{
	scanf("%s",s+1),cnt[1]=cnt[0]=0,n=strlen(s+1);
	for (int i=1; i<=n; i++) cnt[s[i]-'0']++;
	scanf("%s",t+1),n=strlen(t+1);
	nxt[0]=nxt[1]=0; int j=0;
	for (int i=2; i<=n; i++)
	{
		while (j&&t[j+1]!=t[i]) j=nxt[j];
		if (t[j+1]==t[i]) j++;
		nxt[i]=j;
	}
	for (int i=1; i<=n; i++) 
	{
		if (!cnt[t[i]-'0']) work();
		cnt[t[i]-'0']--,putchar(t[i]);
	}
	j=n;
	while (1)
	{
		if (j==n) j=nxt[n]; j++;
		if (!cnt[t[j]-'0']) work();
		cnt[t[j]-'0']--,putchar(t[j]);	
	}
	return 0;
}