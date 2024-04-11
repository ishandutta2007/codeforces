#include<bits/stdc++.h>
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[10];
void move(int s)
{
	cout<<"next";
	for (int i=0;i<10;i++) if ((s>>(9-i))&1) putchar(' '),putchar(i+'0');
	putchar('\n');
	fflush(stdout);
	char c;
	int cnt=0;
	do
	{
		cnt++;
		c=getchar();
		while (!isdigit(c)) c=getchar();
		while (isdigit(c)) a[c-'0']=cnt,c=getchar();
	}while (c==' ');
}

signed main()
{
	do {move(0b1000000000);if (a[0]==a[1]) break;move(0b1100000000);} while (a[0]!=a[1]);
	do {move(0b1010000000);}while (a[0]!=a[1]);
	while (a[2]!=a[3]) move(0b1111111111);
	while (a[0]!=a[2]) move(0b1100000000);
	puts("done");
	fflush(stdout);

	return 0;
}