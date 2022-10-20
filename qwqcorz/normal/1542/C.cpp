#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=1e9+7;

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
int gcd(int x,int y){return !y?x:gcd(y,x%y);}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),lcm=1,ans=0;
		for (int i=2;;i++)
		{
			int nlcm=lcm/gcd(lcm,i)*i;
			ans=(ans+(n/lcm-n/nlcm)%p*i+p)%p;
			if ((lcm=nlcm)>n) break;
		}
		print(ans);
	} 
	
	return 0;
}