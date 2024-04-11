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
char a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	vector<char>ans;
	scanf("%s",a+1);
	int n=strlen(a+1),l,r;
	for (l=1,r=n;r-l+1>=4;l+=2,r-=2)
	{
		bool flag=0;
		for (int j=l;j<=l+1;j++)
		for (int k=r-1;k<=r;k++)
		if (!flag&&a[j]==a[k])
		{
			ans.push_back(a[j]);
			flag=1;
		}
	}
	for (char i:ans) putchar(i);
	if (l<=r) putchar(a[l]);
	reverse(ans.begin(),ans.end());
	for (char i:ans) putchar(i);
	
	return 0;
}