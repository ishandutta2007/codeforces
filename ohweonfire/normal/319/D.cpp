#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;
const int maxn=50005;
const uLL base=29;
char s[2][maxn];
int len,cur,duang[maxn];
void go(int l)
{
	int match=0,nlen=0;
	for(int i=l;i<len;i++)
	{
		if(s[cur][i]==s[cur][i-l])match++;
		else match=0;
		if(match==l)
		{
			duang[i-l]=l;
			match=0;
		}
	}
	for(int i=0;i<len;i++)
	{
		if(i>=len-l)s[cur^1][nlen++]=s[cur][i];
		else if(duang[i]==l)i+=l-1;
		else s[cur^1][nlen++]=s[cur][i];
	}
	cur^=1;
	len=nlen;
}
int main()
{
	scanf("%s",s[0]);
	len=strlen(s[0]);
	for(int i=1;i<=(len>>1);i++)go(i);
	for(int i=0;i<len;i++)putchar(s[cur][i]);
	return 0;
}