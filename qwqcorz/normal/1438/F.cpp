#include<bits/stdc++.h>
using namespace std;
const int N=1<<19;

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
int Q(int A,int B,int C)
{
	printf("? %d %d %d\n",A,B,C);
	fflush(stdout);
	return read();
}
void A(int A)
{
	printf("! %d\n",A);
	fflush(stdout);
	exit(0);
}
int rnd(int n)
{
	int ret=0;
	for (int i=1;i<=6;i++) ret=ret*10+rand()%10;
	return ret%n+1;
}
int a[N];

signed main()
{
	srand(time(0));
	int h=read(),n=(1<<h)-1;
	for (int i=1;i<=420;i++)
	{
		int A=rnd(n),B=rnd(n),C=rnd(n);
		while (A==B||A==C||B==C)
		{
			A=rnd(n);
			B=rnd(n);
			C=rnd(n);
		}
		a[Q(A,B,C)]++;
	}
	int Max1=1,Max2=2;
	if (a[Max1]<a[Max2]) swap(Max1,Max2);
	for (int i=3;i<=n;i++)
	if (a[i]>=a[Max1])
	{
		Max2=Max1;
		Max1=i;
	}
	else if (a[i]>a[Max2]) Max2=i;
	for (int i=1;i<=n;i++)
	if (Max1!=i&&Max2!=i)
	if (Q(Max1,Max2,i)==i)
	A(i);

	return 0;
}