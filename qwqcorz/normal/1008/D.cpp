#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int ans[N];

signed main()
{
	for (int i=1;i<=1e5;i++)
	for (int j=i;j<=1e5;j+=i) ans[j]++;
	int T=read();
	while (T--)
	{
		int A=read(),B=read(),C=read();
		int a=ans[A],b=ans[B],c=ans[C];
		int ab=ans[gcd(A,B)],ac=ans[gcd(A,C)],bc=ans[gcd(B,C)];
		int abc=ans[gcd(gcd(A,B),C)];
		print(
		a*b*c
		-ab*(ab-1)*c/2
		-ac*(ac-1)*b/2
		-bc*(bc-1)*a/2
		-(ab-abc)*(ac-abc)*(bc-abc)
		+4*abc*(abc-1)*(abc-2)/6
		+abc*(abc-1)
		+(ab+ac+bc-3*abc)*abc*(abc-1)/2
		);
	}

	return 0;
}