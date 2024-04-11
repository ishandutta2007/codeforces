#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
char s[N];
void Multi_test_no_horses()
{
	int n=read(),ans=N;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	for (int j=i,a=0,b=0,c=0;j<=min(i+10,n);j++)
	{
		if (s[j]=='a') a++;
		else if (s[j]=='b') b++;
		else c++;
		if (j>i&&a>b&&a>c) ans=min(ans,j-i+1);
	}
	print(ans==N?-1:ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}