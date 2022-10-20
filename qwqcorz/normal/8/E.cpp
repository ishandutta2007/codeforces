#include<bits/stdc++.h>
#define int long long
using namespace std;

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
void Print(int x,int bit)
{
	if (bit==0) return;
	Print(x>>1,bit-1);
	putchar((x&1)+'0');
}
int rev[1<<13];
inline int reverse(int x,int half)
{
	return (rev[x>>13]|(rev[x&((1<<13)-1)]<<13))>>(26-half);
}

signed main()
{
	int n=read(),k=read(),half=n/2,Xor=(1<<half)-1,up=1<<half;
	for (int i=0;i<(1<<13);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<12);
	for (int i=0;i<(1<<(half-1));i++)
	{
		int now=(((1<<(half-1))-i)<<(1+(n&1)))-(n&1)-!i;
		if (k>now) k-=now;
		else
		{
			for (int j=1;j<up;j++)
			if (reverse(j,half)>=i&&reverse(j^Xor,half)>=i)
			{
				k--;
				if (!k)
				{
					Print(i,half);
					if (n&1) putchar('0');
					Print(j,half);
					return 0;
				}
			}
			if (n&1)
			for (int j=0;j<up;j++)
			if (reverse(j,half)>=i&&reverse(j^Xor,half)>i)
			{
				k--;
				if (!k)
				{
					Print(i,half);
					putchar('1');
					Print(j,half);
					return 0;
				}
			}
		}
	}
	puts("-1");

	return 0;
}