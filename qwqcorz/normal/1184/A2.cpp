#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
char s[N];
int a[N],b[N],can[N];

signed main()
{
	int n=read();
	scanf("%s",s);
	for (int i=0;i<n;i++) a[i]=s[i]=='1';
	for (int k=1;k<=n;k++)
	if (n%k==0)
	{
		can[k]=1;
		for (int i=0;i<k;i++) b[i]=0;
		for (int i=0;i<n;i++) b[i%k]^=a[i];
		for (int i=0;i<k;i++) can[k]&=!b[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++) if (can[gcd(n,i)]) ans++;
	print(ans);
	
	return 0;
}