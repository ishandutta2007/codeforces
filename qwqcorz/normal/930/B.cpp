#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;

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
int tot[26][N][26];

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1),ans=0;
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) tot[a[i]-'a'][j][a[i+j-1]-'a']++;
	for (int i=0;i<26;i++)
	{
		int Max=0;
		for (int j=1;j<=n;j++)
		{
			int sum=0;
			for (int k=0;k<26;k++) sum+=tot[i][j][k]==1;
			Max=max(Max,sum);
		}
		ans+=Max;
	}
	printf("%.10lf",1.0*ans/n);
	
	return 0;
}