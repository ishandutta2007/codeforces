#include<bits/stdc++.h>
using namespace std;
const int N=105;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
char a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		scanf("%s",a+1);
		int n=strlen(a+1),sum=0,tot[10]={0,0,0,0,0,0,0,0,0,0},t=0;
		for (int i=1;i<=n;i++) tot[a[i]-'0']++;
		for (int i=1;i<=n;i++) sum+=a[i]-'0';
		if (sum%3) {puts("cyan");continue;}
		if (!tot[0]) {puts("cyan");continue;}
		for (int i=0;i<9;i+=2) t+=tot[i];
		puts(t>=2?"red":"cyan");
	}
	
	return 0;
}